/*
 * 두 정수 A와 B가 주어졌을 때, A와 B를 비교하는 프로그램을 작성
 */

#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	if (a > b)
	{
		cout << ">";
	}
	else if (a < b)
	{
		cout << "<";
	}
	else
	{
		cout << "==";
	}

	return 0;
}