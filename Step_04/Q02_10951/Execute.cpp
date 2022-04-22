/*
문제
두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.

입력
입력은 여러 개의 테스트 케이스로 이루어져 있다.

각 테스트 케이스는 한 줄로 이루어져 있으며, 각 줄에 A와 B가 주어진다. (0 < A, B < 10)

출력
각 테스트 케이스마다 A+B를 출력한다.
*/

#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	while (true)
	{
		cin >> a >> b;
		// EOF(End Of File) 파일의 끝, 더 이상 읽을 데이터가 없다.
		// cin으로 입력을 받으려고 할 때, EOF라면 입력이 취소되고 cin.eof()는 true를 반환한다. 이를 이용하여 파일이 종료될 때까지 입력을 받는 코드를 작성할 수 있다.
		if (cin.eof() == true)
		{
			break;
		}
		cout << a + b << '\n';
	}

	return 0;
}




