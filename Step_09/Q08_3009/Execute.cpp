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

	// 직사각형은 2개의 같은 x값과 2개의 같은 y값이 존재
	int equalX = 0; // 같은 x값
	int equalY = 0; // 같은 y값
	// 같은 값을 가진 x,y 값을 뽑는 과정
	for (int i = 0; i < 3; i++)
	{
		for (int j = i + 1; j < 3; j++)
		{
			if(rect[i].x == rect[j].x)
			{
				equalX = rect[i].x;
			}

			if (rect[i].y == rect[j].y)
			{
				equalY = rect[i].y;
			}
		}
	}

	Vertex v; // 필요한 4번째 점
	// 같지 않은 x값과 같지 않은 y값을 뽑는 과정
	for (int i = 0; i < 3; i++)
	{
		if(equalX != rect[i].x)
		{
			v.x = rect[i].x;
		}

		if (equalY != rect[i].y)
		{
			v.y = rect[i].y;
		}
	}

	cout << v.x << " " << v.y;
	return 0;
}