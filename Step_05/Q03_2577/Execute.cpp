/*

*/

#include <iostream>
using namespace std;

// �� �ڸ����� ���� ���ϴ� �Լ� 
int GetRadixNum(int n, int radix)
{
	return (n / radix) % 10;
}

// �ִ� �ڸ��� ���ϴ� �Լ� 
int MaxRadix(int n)
{
	int i = 1;

	// n�� i���� �۾����� �ݺ� �ߴ� 
	while (n >= i) 
	{
		i *= 10;
	}

	return i;
}

void Count(int arr[], int arrSize, int mul, int maxRadix)
{
	for (int i = 0; i < arrSize; i++) // 0 ~ 9 ����
	{
		for (int j = 1; j < maxRadix; j *= 10) //���� �ڸ������� �ִ� �ڸ�����ŭ Ȯ�� 
		{
			if (i == GetRadixNum(mul, j))
			{
				arr[i] += 1;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// �Է¹��� a,b,c
	int a, b, c;
	cin >> a >> b >> c;
	int mul = a * b * c;

	// 0 ~ 9 �� Ƚ���� ���� �迭
	int arr[10];
	for (int i = 0; i < 10; i++)
	{
		arr[i] = 0;
	}
	Count(arr, 10, mul, MaxRadix(mul));

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << '\n';
	}
	
	return 0;
}