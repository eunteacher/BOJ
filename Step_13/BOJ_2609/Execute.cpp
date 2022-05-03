/*
����
�� ���� �ڿ����� �Է¹޾� �ִ� ������� �ּ� ������� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ��� �� ���� �ڿ����� �־�����. �� ���� 10,000������ �ڿ����̸� ���̿� �� ĭ�� ������ �־�����.

���
ù° �ٿ��� �Է����� �־��� �� ���� �ִ�������, ��° �ٿ��� �Է����� �־��� �� ���� �ּ� ������� ����Ѵ�.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// �ִ� ����� ���ϱ� - �ݺ���
int GetGCD(int a, int b)
{
	// 1���� ���� �ִ񰪱��� ��� ����� �� �˻��Ͽ� �ִ� ��ȯ
	//int max = 0;
	//int range = min(a, b);
	//for (int i = 1; i <= range; i++)
	//{
	//	if (a % i == 0 && b % i == 0)
	//		max = i;
	//}
	// return max;

	// ��Ŭ���� ȣ���� �̿�
	// f(a,b) = gcd(a,b)�� �Ҷ�, a mod b = 0 �̶�� f(a,b) = b�̰�, a mod b = 0 �� �ƴ϶�� f(a,b) = f(b, a mod b)�� ���� 
	//int mod = a % b;
	//while (mod > 0)
	//{
	//	a = b;
	//	b = mod;
	//	mod = a % b;
	//}

	if (a % b == 0)
		return b;
	else
		return GetGCD(b, a % b);

	return b;
}
// �ִ� ����� ���ϱ� - ����Լ�
int GetGCD2(int a, int b)
{
	if (a % b == 0)
		return b;
	else
		return GetGCD2(b, a % b);
}
// �ּ� ����� ���ϱ�
// a * b = GCD(a,b) * LCM(a,b)
int GetLCM(int a, int b)
{
	return (a * b) / GetGCD(a, b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	cin >> a >> b;
	cout << GetGCD(a, b) << '\n';
	//cout << GetGCD2(a, b) << '\n';
	cout << GetLCM(a, b);

	return 0;
}