/*
문제
과거 이집트인들은 각 변들의 길이가 3, 4, 5인 삼각형이 직각 삼각형인것을 알아냈다. 주어진 세변의 길이로 삼각형이 직각인지 아닌지 구분하시오.

입력
입력은 여러개의 테스트케이스로 주어지며 마지막줄에는 0 0 0이 입력된다. 각 테스트케이스는 모두 30,000보다 작은 양의 정수로 주어지며, 각 입력은 변의 길이를 의미한다.

출력
각 입력에 대해 직각 삼각형이 맞다면 "right", 아니라면 "wrong"을 출력한다.
*/
#include <iostream>
using namespace std;

bool Pythagoras(int a,int b, int c)
{
	// a^2 + b^2 = c^2 인 경우
	// a^2 + c^2 = b^2 인 경우
	// b^2 + c^2 = a^2 인 경우
	if (a * a + b * b == c * c)
		return true;
	else if (a * a + c * c == b * b)
		return  true;
	else if (b * b + c * c == a * a)
		return true;

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while(true)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 0 && b == 0 && c == 0)
			return 0;

		if (Pythagoras(a, b, c) == true)
			cout << "right" << '\n';
		else
			cout << "wrong" << '\n';
	}
	
	return 0;
}