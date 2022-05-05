/*
문제
자연수 \(N\)과 정수 \(K\)가 주어졌을 때 이항 계수
\(\binom{N}{K}\)를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 \(N\)과 \(K\)가 주어진다. (1 ≤ \(N\) ≤ 10, 0 ≤ \(K\) ≤ \(N\))

출력

\(\binom{N}{K}\)를 출력한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 입력받은 n의 순차곱셈(팩토리얼, n!)을 반환
// 재귀함수를 이용
int Factorial(int n)
{
	if (n > 0) return n * Factorial(n - 1);
	return 1; // 0일 경우
}

// 1. 재귀함수와 분할 정복을 통한 이항계수 구하기
// 파스칼의 삼각형의 성질을 이용하여 재귀함수로 구현
// 부분 문제를 중복해서 계산하는 문제가 있다.
int Bonomial(int n, int r)
{
	if (r == 0 || n == r) return 1;
	return Bonomial(n - 1, r - 1) + Bonomial(n - 1, r);
}

// 2. 동적계획법을 통한 이항계수 구하기
// 부분 문제 중복 해결
int DynamicBonomial(int n, int r)
{
	int dp[11][11];
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= min(i, r); j++)
		{
			if (j == 0 || j == i) dp[i][j] = 1;
			else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
	return dp[n][r];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;
	//cout << Bonomial(N, K) << '\n';
	cout << DynamicBonomial(N, K) << '\n';

	return 0;
}