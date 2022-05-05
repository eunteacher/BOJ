/*
����
�ڿ��� \(N\)�� ���� \(K\)�� �־����� �� ���� ���
\(\binom{N}{K}\)�� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� \(N\)�� \(K\)�� �־�����. (1 �� \(N\) �� 10, 0 �� \(K\) �� \(N\))

���

\(\binom{N}{K}\)�� ����Ѵ�.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// �Է¹��� n�� ��������(���丮��, n!)�� ��ȯ
// ����Լ��� �̿�
int Factorial(int n)
{
	if (n > 0) return n * Factorial(n - 1);
	return 1; // 0�� ���
}

// 1. ����Լ��� ���� ������ ���� ���װ�� ���ϱ�
// �Ľ�Į�� �ﰢ���� ������ �̿��Ͽ� ����Լ��� ����
// �κ� ������ �ߺ��ؼ� ����ϴ� ������ �ִ�.
int Bonomial(int n, int r)
{
	if (r == 0 || n == r) return 1;
	return Bonomial(n - 1, r - 1) + Bonomial(n - 1, r);
}

// 2. ������ȹ���� ���� ���װ�� ���ϱ�
// �κ� ���� �ߺ� �ذ�
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