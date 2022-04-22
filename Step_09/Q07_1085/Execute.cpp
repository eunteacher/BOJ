/*
문제
한수는 지금 (x, y)에 있다. 직사각형은 각 변이 좌표축에 평행하고, 왼쪽 아래 꼭짓점은 (0, 0), 오른쪽 위 꼭짓점은 (w, h)에 있다. 직사각형의 경계선까지 가는 거리의 최솟값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 x, y, w, h가 주어진다.

출력
첫째 줄에 문제의 정답을 출력한다.

제한
1 ≤ w, h ≤ 1,000
1 ≤ x ≤ w-1
1 ≤ y ≤ h-1
x, y, w, h는 정수
*/
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x, y, w, h;

	cin >> x >> y >> w >> h;

	// h방향 혹은 w방향과 x축 방향 혹은 y축 방향 이렇게 4개의 방법이 있다.
	// 4가지 방법 중 가장 짧은 길이, 즉 최솟값을 출력하면 된다.

	// 4가지 방법을 배열에 담는다.
	int sides[4];
	sides[0] = w - x;
	sides[1] = h - y;
	sides[2] = x;
	sides[3] = y;

	// 최솟값 구하기
	int min = sides[0];
	for (int i = 0; i < 4; i++)
	{
		if (min > sides[i])
			min = sides[i];
	}

	cout << min;
	
	return 0;
}