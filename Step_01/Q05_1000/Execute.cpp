#include <iostream>
using namespace std;

void Func()
{
	/*
	* ���� : �� ���� A�� B�� �Է¹��� ����, A+B�� ����ϴ� ���α׷��� �ۼ�
	* �Է� : ù° �ٿ� A�� B�� �־�����.(0 < A, B < 10)
	* ���� �Է� : 1 2 , ���� ��� : 3
	*/

	int i = 0;
	int j = 0;

	while (true)
	{
		cin >> i >> j;
		if (i > 0 && j < 10)
		{
			break;
		}
	}

	cout << i + j << endl;


}

int main()
{
	Func();
	return 0;
}