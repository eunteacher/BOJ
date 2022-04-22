/*
 * 연도가 주어졌을 때, 윤년이면 1, 아니면 0을 출력하는 프로그램을 작성
 * 윤년 계산 : 연도가 4의 배수이면서, 100의 배수가 아닐 때 혹은 400의 배수일 때 
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