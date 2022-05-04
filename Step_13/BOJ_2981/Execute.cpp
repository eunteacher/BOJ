/*
문제
트럭을 타고 이동하던 상근이는 경찰의 검문을 받게 되었다. 경찰은 상근이가 운반하던 화물을 하나하나 모두 확인할 것이기 때문에, 검문하는데 엄청나게 오랜 시간이 걸린다.

상근이는 시간을 때우기 위해서 수학 게임을 하기로 했다.

먼저 근처에 보이는 숫자 N개를 종이에 적는다. 그 다음, 종이에 적은 수를 M으로 나누었을 때, 나머지가 모두 같게 되는 M을 모두 찾으려고 한다. M은 1보다 커야 한다.

N개의 수가 주어졌을 때, 가능한 M을 모두 찾는 프로그램을 작성하시오.

입력
첫째 줄에 종이에 적은 수의 개수 N이 주어진다. (2 ≤ N ≤ 100)

다음 줄부터 N개 줄에는 종이에 적은 수가 하나씩 주어진다. 이 수는 모두 1보다 크거나 같고, 1,000,000,000보다 작거나 같은 자연수이다. 같은 수가 두 번 이상 주어지지 않는다.

항상 M이 하나 이상 존재하는 경우만 입력으로 주어진다.

출력
첫째 줄에 가능한 M을 공백으로 구분하여 모두 출력한다. 이때, M은 증가하는 순서이어야 한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 두 수 a, b를 입력으로 받고
// 두 수의 최대 공약수를 구하는 함수
// 유클리드 호제법을 사용하여 구현
// f(a,b) = gcd(a,b)라 할때, a mod b = 0 이라면 f(a,b) = b이고, a mod b = 0 가 아니라면 f(a,b) = f(b, a mod b)가 성립
int GCD(int a, int b)
{
	int mod = a % b;
	while(mod != 0)
	{
		a = b;
		b = mod;
		mod = a % b; // mod가 0이 나오면 반복문 종료
	}

	return b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N; // 개수
	cin >> N;
	vector<int> nums;
	// nums 입력
	for (int i = 0; i < N; i++)
	{
		int tmp = 0;
		cin >> tmp;
		nums.push_back(tmp);
	}

	// 인접한 항의 차를 구해야하기 때문에 값 정렬
	sort(nums.begin(), nums.end()); 

	// 01. 인접한 향 차 구하기
	// 02. 나온 값들의 최대 공약수 구하기
	// 03. 나온 최대공약수의 배수 출력
	vector<int> div; // 인접한 항의 차의 값을 저장할 벡터
	// 01
	for (int i = 1; i < N; i++)
		div.push_back(nums[i] - nums[i - 1]);
	// 02
	int max = GCD(div[1], div[0]); // 최대공약수
	for (int i = 1; i < div.size(); i++)
	{
		if (div[i] > max) max = GCD(div[i], max);
		else max = GCD(max, div[i]);
	}
	// 03
	vector<int> factors; // 최대 공약수의 배수를 저장할 벡터
	for (int i = 1; i * i <= max; i++)
	{
		if (i * i == max) factors.push_back(i);
		else if (max % i == 0)
		{
			factors.push_back(i);
			factors.push_back(max / i);
		}
	}

	// 정렬 후 출력
	sort(factors.begin(), factors.end());
	for (int factor : factors)
	{
		if (factor != 1)
			cout << factor << " ";
	}

	return 0;
}