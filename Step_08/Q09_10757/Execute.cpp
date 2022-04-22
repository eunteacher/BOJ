/*
����
�� ���� A�� B�� �Է¹��� ����, A+B�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� A�� B�� �־�����. (0 < A,B < 1010000)

���
ù° �ٿ� A+B�� ����Ѵ�.
*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string A, B;
	cin >> A >> B;

	string Sum = "";

	int lenA = A.length() - 1;
	int lenB = B.length() - 1;

	// ���ڿ��� ���̸� �Ȱ��� ���ش�.
	string temp = "";
	if (lenA > lenB)
	{
		for (int i = 0; i < lenA - lenB; i++)
		{
			temp += "0";
		}
		B = temp + B;
	}
	else
	{
		// lenA < lenB
		for (int i = 0; i < lenB - lenA; i++)
		{
			temp += "0";
		}
		A = temp + A;
	}

	int len = A.length();
	int a, b, sum;
	bool bCarry = false; // �ø� ǥ��

	// 1�� �ڸ����� ����
	for (int i = len - 1; i >= 0; i--)
	{
		a = A[i] - '0';
		b = B[i] - '0';
		sum = a + b;

		if (bCarry == true)
		{
			sum += 1;
			bCarry = false;
		}

		// 10 �̻��̸� �� �ڸ��� 1 �÷���ߵȴ�.
		if (sum > 9)
		{
			Sum += to_string(sum % 10);
			bCarry = true;
		}
		else
		{
			Sum += to_string(sum);
		}
	}

	if (bCarry == true)
	{
		Sum += "1";
	}

	reverse(Sum.begin(), Sum.end());

	cout << Sum;

	return 0;
}