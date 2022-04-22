/*
문제
두 자연수 A와 B가 있을 때, A%B는 A를 B로 나눈 나머지 이다. 예를 들어, 7, 14, 27, 38을 3으로 나눈 나머지는 1, 2, 0, 2이다.

수 10개를 입력받은 뒤, 이를 42로 나눈 나머지를 구한다. 그 다음 서로 다른 값이 몇 개 있는지 출력하는 프로그램을 작성하시오.

입력
첫째 줄부터 열번째 줄 까지 숫자가 한 줄에 하나씩 주어진다. 이 숫자는 1,000보다 작거나 같고, 음이 아닌 정수이다.

출력
첫째 줄에, 42로 나누었을 때, 서로 다른 나머지가 몇 개 있는지 출력한다.
*/

#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[10];
	for (int i = 0; i < 10; i++) 
	{
		cin >> arr[i]; // 값 입력
		arr[i] %= 42; // 나머지 값
	}

	int same[42]; // 나머지는 0 ~ 41 까지의 숫자
	for (int i = 0; i < 42; i++)
	{
		same[i] = 0; // 배열을 전부 0으로 할당
		for (int j = 0; j < 10; j++)
		{
			if (arr[j] == i) // arr[j]의 값과 나머지 인 i가 같으면 
			{
				same[i] += 1; // same +1
			}
		}
	}

	int result = 0; // 다른 수의 개수
	for (int i = 0; i < 42; i++)
	{
		if (same[i] != 0) // same[i] == 0 은 arr배열에 그 숫자가 없다는 의미
		{
			result++;
		}
	}
	cout << result;

	/* 또 다른 방법
		int same[42] = { 0, };
		for (int i = 0; i < 10; i++)
		{
			same[arr[i] % 42] = 1;
		}

		int result = 0;

		for (int i = 0; i < 42; i++)
		{
			result += same[i];
		}

		cout << result;
	*/




	return 0;
}