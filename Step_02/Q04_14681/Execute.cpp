/*
 * 흔한 수학 문제 중 하나는 주어진 점이 어느 산분면에 속하는지 알아내는 것이다. 사분면은 아래 그림처럼 1~4까지 번호를 갖는다.
 * "Quadrant n"은 "제 n사분면"이라는 뜻이다. 예를 들어 좌표가 (12, 5)인 점 A는 x좌표와 y좌표가 모두 양수이므로 제 1사분면에 속한다. 점 B는 x좌표가 음수이고 y좌표가 양수이므로
 * 제 2사분면에 속한다. 점의 좌표를 입력받아 그 점이 어느 산분면에 속하는지 알아내는 프로그램을 작성하시오.
 */

#include <iostream>
using namespace std;

int WhatQuad(int x, int y)
{
	if (x > 0 && y > 0)
	{
		return 1;
	}
	else if (x < 0 && y > 0)
	{
		return 2;
	}
	else if (x < 0 && y < 0)
	{
		return 3;
	}
	else if (x > 0 && y < 0)
	{
		return 4;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int x, y;
	cin >> x >> y;

	cout << WhatQuad(x, y);

	return 0;
}