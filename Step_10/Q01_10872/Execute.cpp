/*
����
0���� ũ�ų� ���� ���� N�� �־�����. �̶�, N!�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� N(0 �� N �� 12)�� �־�����.

���
ù° �ٿ� N!�� ����Ѵ�.
*/
#include <iostream>
using namespace std;

int Factorial(int i)
{
	if(i > 0)
		return i * Factorial(i - 1);
	else
		return 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int I;
	cin >> I;

	cout << Factorial(I);
	return 0;
}