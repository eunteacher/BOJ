#include <iostream>
using namespace std;

void Func()
{
	/*
	* 문제 : 두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성
	* 입력 : 첫째 줄에 A와 B가 주어진다.(0 < A, B < 10)
	* 예제 입력 : 1 2 , 예제 출력 : 3
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