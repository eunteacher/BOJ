/*
문제
상근이는 창고에서 링 N개를 발견했다. 상근이는 각각의 링이 앞에 있는 링과 뒤에 있는 링과 접하도록 바닥에 내려놓았다.

상근이는 첫 번째 링을 돌리기 시작했고, 나머지 링도 같이 돌아간다는 사실을 발견했다. 나머지 링은 첫 번째 링 보다 빠르게 돌아가기도 했고, 느리게 돌아가기도 했다. 이렇게 링을 돌리다 보니 첫 번째 링을 한 바퀴 돌리면, 나머지 링은 몇 바퀴 도는지 궁금해졌다.

링의 반지름이 주어진다. 이때, 첫 번째 링을 한 바퀴 돌리면, 나머지 링은 몇 바퀴 돌아가는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 링의 개수 N이 주어진다. (3 ≤ N ≤ 100)

다음 줄에는 링의 반지름이 상근이가 바닥에 놓은 순서대로 주어진다. 반지름은 1과 1000를 포함하는 사이의 자연수이다.

출력
출력은 총 N-1줄을 해야 한다. 첫 번째 링을 제외한 각각의 링에 대해서, 첫 번째 링을 한 바퀴 돌리면 그 링은 몇 바퀴 도는지 기약 분수 형태 A/B로 출력한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 숫자를 입력받아 그 숫자의 약수들을 저장한 벡터를 반환
vector<int> GetFactor(int n)
{
	vector<int> tmp;

	for (int i = 1; i * i <= n; i++)
	{
		if (i * i == n)
			tmp.push_back(i);
		else if(n % i == 0)
		{
			tmp.push_back(i);
			tmp.push_back(n / i);
		}
	}

	// 정렬
	sort(tmp.begin(), tmp.end());

	return tmp;
}

// 입력받은 벡터에 n이 존재하는지 판단
// 이진 탐색 사용
bool IsExist(vector<int> vec, int n)
{
	int left = 0;
	int right = vec.size() - 1;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (vec[mid] == n) return true;
		else if (vec[mid] < n) left = mid + 1;
		else if (vec[mid] > n) right = mid - 1;
	}

	return false;
}

// 최대 공약수를 반환
// 유클리드 호제법 - 재귀함수 사용
int Gcd(int a, int b)
{
	if (a % b == 0) return b;
	else return Gcd(b, a % b);
}
// 최대 공배수를 반환
int Lcm(int a, int b)
{
	return (a * b) / Gcd(a, b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N; // 링의 개수
	cin >> N;
	vector<int> rings; // 링의 반지름을 저장한 벡터, 링의 반지름 1 ~ 1000
	// 입력 받기 
	for (int i = 0; i < N; i++)
	{
		int radius;
		cin >> radius;
		rings.push_back(radius);
	}

	// 1. 1번째링의 약수를 구한다.
	// 2. 1번째 링을 제외하고 반복문 실행
	// 3. 1번째 링의 약수에 포함하는지 확인
	// 3-1. true일 경우 최소공배수와 반지름을 나누어 몫을 출력
	// 3-2. false일 경우 최소공배수를 구하고, 최소공배수와 반지름을 나누어 몫을 출력
	vector<int> first = GetFactor(rings.front()); // 1번째링의 약수
	for (int i = 1; i < rings.size(); i++)
	{
		if (IsExist(first, rings[i]) == true) cout << rings[0] / rings[i] << "/1" << '\n';
		else
		{
			int lcm = Lcm(rings[i], rings[0]);
			cout << lcm / rings[i] << "/" << lcm / rings[0] << '\n';
		}
	}
	return 0;
}