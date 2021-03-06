/*
문제


위의 그림과 같이 육각형으로 이루어진 벌집이 있다. 그림에서 보는 바와 같이 중앙의 방 1부터 시작해서 이웃하는 방에 돌아가면서 1씩 증가하는 번호를 주소로 매길 수 있다. 숫자 N이 주어졌을 때, 벌집의 중앙 1에서 N번 방까지 최소 개수의 방을 지나서 갈 때 몇 개의 방을 지나가는지(시작과 끝을 포함하여)를 계산하는 프로그램을 작성하시오. 예를 들면, 13까지는 3개, 58까지는 5개를 지난다.

입력
첫째 줄에 N(1 ≤ N ≤ 1,000,000,000)이 주어진다.

출력
입력으로 주어진 방까지 최소 개수의 방을 지나서 갈 때 몇 개의 방을 지나는지 출력한다.
*/
#include <iostream>
using namespace std;

int main()
{
	// 등차 수열, 등차 수열의 합, 수열 점화식에 관한 문제  

	unsigned long long n;
	cin >> n;
	unsigned long long count = 1;
		
	if (n == 1)
	{
		cout << count;
	}
	else
	{
		while (true)
		{
			// 시작
			unsigned long long start = (3 * count * count) - (9 * count) + 8;
			// 끝
			unsigned long long end = (3 * count * count) - (3 * count) + 1;

			if (start <= n && end >= n)
			{
				break;
			}
			count++;
		}

		cout << count;
	}
	
	return 0;
}
