/*
문제
베르트랑 공준은 임의의 자연수 n에 대하여, n보다 크고, 2n보다 작거나 같은 소수는 적어도 하나 존재한다는 내용을 담고 있다.

이 명제는 조제프 베르트랑이 1845년에 추측했고, 파프누티 체비쇼프가 1850년에 증명했다.

예를 들어, 10보다 크고, 20보다 작거나 같은 소수는 4개가 있다. (11, 13, 17, 19) 또, 14보다 크고, 28보다 작거나 같은 소수는 3개가 있다. (17,19, 23)

자연수 n이 주어졌을 때, n보다 크고, 2n보다 작거나 같은 소수의 개수를 구하는 프로그램을 작성하시오.

입력
입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 케이스는 n을 포함하는 한 줄로 이루어져 있다.

입력의 마지막에는 0이 주어진다.

출력
각 테스트 케이스에 대해서, n보다 크고, 2n보다 작거나 같은 소수의 개수를 출력한다.
*/
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	do
	{
		int prime = 0; // 소수의 개수 
		cin >> N;

		// 종료 
		if (N == 0)
		{
			return 0;
		}
		// 1일 경우 출력
		if (N == 1)
		{
			cout << N << '\n';
			continue;
		}
		
		int m = 2 * N;
		for (N += 1; N <= m; N++) // N +1 ~ 2N 까지 검사
		{
			bool flag = true; // 소수일 경우 true 아니면 false
			for (int i = 2; i * i <= N; i++) // 소수인지 검사
			{
				if (N % i == 0) // 소수가 아닌 경우 반복문을 종료한다.
				{
					flag = false;
					break;
				}
			}
			if (flag == true)
				prime++; // 소수일 경우 +1
		}
		
		cout << prime << '\n';

	} while (true);

	return 0;
}