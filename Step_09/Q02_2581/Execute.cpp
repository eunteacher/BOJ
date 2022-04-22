/*
����
�ڿ��� M�� N�� �־��� �� M�̻� N������ �ڿ��� �� �Ҽ��� ���� ��� ��� �̵� �Ҽ��� �հ� �ּڰ��� ã�� ���α׷��� �ۼ��Ͻÿ�.

���� ��� M=60, N=100�� ��� 60�̻� 100������ �ڿ��� �� �Ҽ��� 61, 67, 71, 73, 79, 83, 89, 97 �� 8���� �����Ƿ�, �̵� �Ҽ��� ���� 620�̰�, �ּڰ��� 61�� �ȴ�.

�Է�
�Է��� ù° �ٿ� M��, ��° �ٿ� N�� �־�����.

M�� N�� 10,000������ �ڿ����̸�, M�� N���� �۰ų� ����.

���
M�̻� N������ �ڿ��� �� �Ҽ��� ���� ��� ã�� ù° �ٿ� �� ����, ��° �ٿ� �� �� �ּڰ��� ����Ѵ�.

��, M�̻� N������ �ڿ��� �� �Ҽ��� ���� ���� ù° �ٿ� -1�� ����Ѵ�.
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

	// m�� ¦���� ���
	if (m % 2 == 0 && m != 2)
		m += 1; // Ȧ��
	
	if(min != 2)
		min = n;

	// ¦���� ����� �ʿ䰡 ����.
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
			sum += m; // �Ҽ����� ��
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

	// �Ҽ����� ��, �ּڰ�
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