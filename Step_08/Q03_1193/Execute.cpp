/*
����
������ ū �迭�� ������ ���� �м����� �����ִ�.

1/1	1/2	1/3	1/4	1/5	��
2/1	2/2	2/3	2/4	��	��
3/1	3/2	3/3	��	��	��
4/1	4/2	��	��	��	��
5/1	��	��	��	��	��
��	��	��	��	��	��
�̿� ���� ������ �м����� 1/1 �� 1/2 �� 2/1 �� 3/1 �� 2/2 �� �� �� ���� ������� ������ ���ʴ�� 1��, 2��, 3��, 4��, 5��, �� �м���� ����.

X�� �־����� ��, X��° �м��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� X(1 �� X �� 10,000,000)�� �־�����.

���
ù° �ٿ� �м��� ����Ѵ�.
*/
#include <iostream>
using namespace std;

int main()
{
	int input;
	cin >> input;

	int d = 1; // �и�
	int n = 1; // ����

	bool x = false; // d == 1�϶� false�� n++
	bool y = false; // n == 1�϶� true�� d++
	bool z = false; // false�� n--, d++

	if (input == 1)
	{
		cout << n << "/" << d;
	}
	else
	{
		for (int i = 2; i < input + 1; i++)
		{
			if (d == n)
			{
				d++;
				if (n != 1)
				{
					if (z == false)
					{
						n--;
					}
					else
					{
						n++;
					}
				}
			}
			else if (d > n)
			{
				if (n == 1 && y == false)
				{
					n++;
					d--;
					y = true;
				}
				else if(n == 1 && y == true)
				{
					d++;
					y = false;
					z = true;
				}
				else
				{
					if (z == true)
					{
						n++;
						d--;
					}
					else
					{
						n--;
						d++;
					}

				}
			}
			else
			{
				if (d == 1 && x == false)
				{
					n++;
					x = true;
					z = false;
				}
				else if (d == 1 && x == true)
				{
					n--;
					d++;
					x = false;
				}
				else
				{
					if (z == true)
					{
						n++;
						d--;
					}
					else
					{
						n--;
						d++;
					}
				}
			}
		}
		cout << n << "/" << d;
	}

	

	return 0;
}

