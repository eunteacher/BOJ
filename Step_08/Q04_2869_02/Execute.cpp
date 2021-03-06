/*
문제
땅 위에 달팽이가 있다. 이 달팽이는 높이가 V미터인 나무 막대를 올라갈 것이다.

달팽이는 낮에 A미터 올라갈 수 있다. 하지만, 밤에 잠을 자는 동안 B미터 미끄러진다. 또, 정상에 올라간 후에는 미끄러지지 않는다.

달팽이가 나무 막대를 모두 올라가려면, 며칠이 걸리는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 세 정수 A, B, V가 공백으로 구분되어서 주어진다. (1 ≤ B < A ≤ V ≤ 1,000,000,000)

출력
첫째 줄에 달팽이가 나무 막대를 모두 올라가는데 며칠이 걸리는지 출력한다.
*/
#include <iostream>
using namespace std;

int main()
{
	// 입력 값
	int V, A, B;
	cin >> A >> B >> V;

	// 최종 도달 할 거리 : V-A
	// V-A를 가는데 걸리는 시간 : (V-A) / (A-B)
	// (V-A) / (A-B)의 나머지가 0이 아닌 경우 정상에 도달하기에 거리가 모자르니까 +1을 해준다. +1을 해준 이유는 다음날 낮에 정상에 도달하기 떄문에  
	// (V-A) / (A-B)의 나머지가 0인 경우는 (V-A) / (A-B)일만큼 오르고, 마지막 날에 A만큼 올라 정상에 도달

	int time = 1;
	time += (V - A) / (A - B);
	if ((V - A) % (A - B) != 0)
		time++;

	if (A >= V)
		cout << 1;
	else
		cout << time;

	return 0;
}

