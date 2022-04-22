/*
문제
어떤 양의 정수 X의 각 자리가 등차수열을 이룬다면, 그 수를 한수라고 한다. 등차수열은 연속된 두 개의 수의 차이가 일정한 수열을 말한다. N이 주어졌을 때, 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 1,000보다 작거나 같은 자연수 N이 주어진다.

출력
첫째 줄에 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력한다.
*/
#include <iostream>
using namespace std;

int Count(int input)
{
	int result = 0;

	// 한수 판단 
	for (int i = 1; i <= input; i++)
	{
		// 1 ~ 999, 1000은 등차수열을 이루지 않기 때문에 제외
		int a = (i / 1) % 10; // 1의 자릿수
		int b = (i / 10) % 10; // 10의 자릿수
		int c = (i / 100) % 10; // 100의 자릿수

		// 0이 공차가 될 수 있다.

		// i가 1의 자리일 경우 
		if (a != 0 && b == 0 && c == 0)
		{
			result++;
		}
		// i가 10의 자리일 경우
		if (b != 0 && c == 0)
		{
			result++;
		}

		// i가 100의 자리일 경우 
		if (c != 0)
		{
			int t = b - a; // 공차
			if (c == a + 2 * t) // c는 2번쨰 항, a는 초항, n번째 항 = 초항 + (n - 1)공차
			{
				result++;
			}
		}
	}

	return result;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int input;
	cin >> input;

	cout << Count(input) << '\n';

	return 0;
}