/*
 * ������ �־����� ��, �����̸� 1, �ƴϸ� 0�� ����ϴ� ���α׷��� �ۼ�
 * ���� ��� : ������ 4�� ����̸鼭, 100�� ����� �ƴ� �� Ȥ�� 400�� ����� �� 
 */

#include <iostream>
using namespace std;

int IsLeaf(int year)
{
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

int main()
{
	int year;
	cin >> year;

	cout << IsLeaf(year);

	return 0;
}