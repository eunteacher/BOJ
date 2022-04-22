/*
����
� �ڿ��� N�� ���� ��, �� �ڿ��� N�� �������� N�� N�� �̷�� �� �ڸ����� ���� �ǹ��Ѵ�. � �ڿ��� M�� �������� N�� ���, M�� N�� �����ڶ� �Ѵ�. ���� ���, 245�� �������� 256(=245+2+4+5)�� �ȴ�. ���� 245�� 256�� �����ڰ� �ȴ�. ����, � �ڿ����� ��쿡�� �����ڰ� ���� ���� �ִ�. �ݴ��, �����ڰ� ���� ���� �ڿ����� ���� �� �ִ�.

�ڿ��� N�� �־����� ��, N�� ���� ���� �����ڸ� ���س��� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �ڿ��� N(1 �� N �� 1,000,000)�� �־�����.

���
ù° �ٿ� ���� ����Ѵ�. �����ڰ� ���� ��쿡�� 0�� ����Ѵ�.
*/
#include <iostream>
#include <vector>
using namespace std;

int GetDigit(int n)
{
	int count = 1;
	while (n > 1)
	{
		n /= 10;
		count *= 10;
	}
	return count;
}

int GetNum(int n, int digit)
{
	return (n / digit) % 10;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> c; // �����ڸ� ���� �迭

	for (int i = 1; i <= 1000000; i++)
	{
		int maxDigit = GetDigit(i); // �ִ� �ڸ���
		int sum = 0; // ��
		for (int j = 1; j <= maxDigit; j *= 10)
		{
			sum += GetNum(i, j); // �� �ڸ����� ��
		}
		sum += i; // �ڱ� �ڽ� ��
		if (sum == N) // ������
			c.push_back(i);
	}

	if (c.empty() == true)
	{
		// ��� ������ 0 ���
		cout << 0;
		return 0;
	}
	else
	{
		// ������ �� �ּڰ� ã�� 
		int min = c[0];
		for (int i = 1; i < c.size(); i++)
		{
			if (min > c[i])
				min = c[i];
		}
		cout << min;
	}

	return 0;
}