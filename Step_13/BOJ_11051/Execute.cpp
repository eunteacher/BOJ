/*
문제
자연수 \(N\)과 정수 \(K\)가 주어졌을 때 이항 계수
\(\binom{N}{K}\)를 10,007로 나눈 나머지를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 \(N\)과 \(K\)가 주어진다. (1 ≤ \(N\) ≤ 1,000, 0 ≤ \(K\) ≤ \(N\))

출력

\(\binom{N}{K}\)를 10,007로 나눈 나머지를 출력한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 동적 계획법을 이용하여 이항계수 값 반환 
int DynamicBonomial(int n, int r)
{
	// dp 벡터 선언
	vector<vector<int>> dp;
	// 메모리 할당을 위한 임시 변수
	vector<int> tmp;
	// 메모리 미리 할당
	tmp.assign(1001, 0);
	dp.assign(1001, tmp);

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= min(i, r); j++)
		{
			if (j == 0 || j == i) dp[i][j] = 1;
			else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007; // 나머지 계산
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
	cout << DynamicBonomial(N, K);

	return 0;
}