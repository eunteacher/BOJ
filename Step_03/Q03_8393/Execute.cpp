/*
 ����
 n�� �־����� ��, 1���� n���� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
 
 �Է�
 ù° �ٿ� n (1 �� n �� 10,000)�� �־�����.
 
 ���
 1���� n���� ���� ����Ѵ�.
*/

#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int result = 0;
	for (int i = 1; i < n + 1; i++)
	{
		result += i;
	}
	cout << result;

	return 0;
}