/*
문제
자연수 M과 N이 주어질 때 M이상 N이하의 자연수 중 소수인 것을 모두 골라 이들 소수의 합과 최솟값을 찾는 프로그램을 작성하시오.

예를 들어 M=60, N=100인 경우 60이상 100이하의 자연수 중 소수는 61, 67, 71, 73, 79, 83, 89, 97 총 8개가 있으므로, 이들 소수의 합은 620이고, 최솟값은 61이 된다.

입력
입력의 첫째 줄에 M이, 둘째 줄에 N이 주어진다.

M과 N은 10,000이하의 자연수이며, M은 N보다 작거나 같다.

출력
M이상 N이하의 자연수 중 소수인 것을 모두 찾아 첫째 줄에 그 합을, 둘째 줄에 그 중 최솟값을 출력한다.

단, M이상 N이하의 자연수 중 소수가 없을 경우는 첫째 줄에 -1을 출력한다.
*/
#include <iostream>
using namespace std;

void FindPrime(int m, int n, int &sum, int &min)
{
	if (m == 1)
	{
		m = 3;
		sum += 2;
		min = 2;
	}

	// m이 짝수일 경우
	if (m % 2 == 0 && m != 2)
		m += 1; // 홀수
	
	if(min != 2)
		min = n;

	// 짝수는 계산할 필요가 없다.
	for (m; m <= n; m += 2)
	{
		bool flag = false;
		for (int i = 2; i * i <= m; i++)
		{
			if (m % i == 0)
			{
				flag = true;
				break;
			}
		}

		if (flag == false)
		{
			sum += m; // 소수들의 합
			if (min > m)
				min = m;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int M, N;
	cin >> M >> N;
	if (M == 1 && N == 1)
	{
		cout << -1;
		return 0;
	}

	// 소수들의 합, 최솟값
	int Sum = 0, Min = 0;
	FindPrime(M, N, Sum, Min);

	if (Sum == 0)
	{
		cout << -1;
		return 0;
	}

	cout << Sum << '\n';
	cout << Min << '\n';

	return 0;
}