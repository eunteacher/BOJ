/*
 ����
 �� ���� A�� B�� �Է¹��� ����, A+B�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
 
 �Է�
 ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����.
 
 �� �׽�Ʈ ���̽��� �� �ٷ� �̷���� ������, �� �ٿ� A�� B�� �־�����. (0 < A, B < 10)
 
 ���
 �� �׽�Ʈ ���̽����� A+B�� ����Ѵ�.
*/

#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a, b;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		cout << a + b << endl;
	}
	
	return 0;
}