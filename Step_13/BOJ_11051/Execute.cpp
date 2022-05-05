/*
����
�ڿ��� \(N\)�� ���� \(K\)�� �־����� �� ���� ���
\(\binom{N}{K}\)�� 10,007�� ���� �������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� \(N\)�� \(K\)�� �־�����. (1 �� \(N\) �� 1,000, 0 �� \(K\) �� \(N\))

���

\(\binom{N}{K}\)�� 10,007�� ���� �������� ����Ѵ�.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ���� ��ȹ���� �̿��Ͽ� ���װ�� �� ��ȯ 
int DynamicBonomial(int n, int r)
{
	// dp ���� ����
	vector<vector<int>> dp;
	// �޸� �Ҵ��� ���� �ӽ� ����
	vector<int> tmp;
	// �޸� �̸� �Ҵ�
	tmp.assign(1001, 0);
	dp.assign(1001, tmp);

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= min(i, r); j++)
		{
			if (j == 0 || j == i) dp[i][j] = 1;
			else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007; // ������ ���
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