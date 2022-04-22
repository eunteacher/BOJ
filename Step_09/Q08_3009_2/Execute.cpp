/*
문제
세 점이 주어졌을 때, 축에 평행한 직사각형을 만들기 위해서 필요한 네 번째 점을 찾는 프로그램을 작성하시오.

입력
세 점의 좌표가 한 줄에 하나씩 주어진다. 좌표는 1보다 크거나 같고, 1000보다 작거나 같은 정수이다.

출력
직사각형의 네 번째 점의 좌표를 출력한다.
*/
#include <iostream>
using namespace std;

// 정점 
struct Vertex
{
	int x;
	int y;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 세 점 
	Vertex rect[3];
	// 세 점의 값 입력
	for (int i = 0; i < 3; i++)
	{
		cin >> rect[i].x >> rect[i].y;
	}

	// 직사각형은 2개의 같은 x값과 2개의 같은 y값이 존재하므로 3개의 점 중 같지 않은 하나의 값이 4번째 점이다.
	Vertex v; // 4번째 점
	if (rect[0].x == rect[1].x)
		v.x = rect[2].x;
	else if(rect[0].x == rect[2].x)
		v.x = rect[1].x;
	else if (rect[1].x == rect[2].x)
		v.x = rect[0].x;

	if (rect[0].y == rect[1].y)
		v.y = rect[2].y;
	else if (rect[0].y == rect[2].y)
		v.y = rect[1].y;
	else if (rect[1].y == rect[2].y)
		v.y = rect[0].y;

	cout << v.x << " " << v.y;
	return 0;
}