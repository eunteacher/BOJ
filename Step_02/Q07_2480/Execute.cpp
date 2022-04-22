/*
 문제
 1에서부터 6까지의 눈을 가진 3개의 주사위를 던져서 다음과 같은 규칙에 따라 상금을 받는 게임이 있다.

 같은 눈이 3개가 나오면 10,000원+(같은 눈)×1,000원의 상금을 받게 된다.
 같은 눈이 2개만 나오는 경우에는 1,000원+(같은 눈)×100원의 상금을 받게 된다.
 모두 다른 눈이 나오는 경우에는 (그 중 가장 큰 눈)×100원의 상금을 받게 된다.
 예를 들어, 3개의 눈 3, 3, 6이 주어지면 상금은 1,000+3×100으로 계산되어 1,300원을 받게 된다. 또 3개의 눈이 2, 2, 2로 주어지면 10,000+2×1,000 으로 계산되어 12,000원을 받게 된다. 3개의 눈이 6, 2, 5로 주어지면 그중 가장 큰 값이 6이므로 6×100으로 계산되어 600원을 상금으로 받게 된다.

 3개 주사위의 나온 눈이 주어질 때, 상금을 계산하는 프로그램을 작성 하시오.

 입력
 첫째 줄에 3개의 눈이 빈칸을 사이에 두고 각각 주어진다.

 출력
 첫째 줄에 게임의 상금을 출력 한다.
*/

#include <iostream>
using namespace std;

// Max 값 구하는 함수 
int Max(int a, int b, int c)
{
	int arr[] = { a,b,c };
	int size = sizeof(arr) / sizeof(int);

	int max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}

	return max;
}

// 같은 값 중 최댓값 구하는 함수
int Equal(int a, int b, int c)
{
	int arr[] = { a,b,c };
	int size = sizeof(arr) / sizeof(int);

	int equal = 0;
	for (int i = 0; i < size; i++)
	{
		equal = arr[i];

		for (int j = 0; j < size; j++)
		{
			if (equal == arr[j] && i != j)
			{
				return equal;
			}
		}
	}

	return equal;
}

int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	int result;

	if (a == b && a == c && b == c) // 모두 같은 경우
	{
		result = 10000 + (a * 1000);
	}
	else if (a == b && a != c && b != c
		|| a == c && a != b && c != b
		|| b == c && b != a && c != a) // 2개가 같은 경우
	{
		result = 1000 + (Equal(a, b, c) * 100);
	}
	else // 모두 다른 경우 
	{
		result = Max(a, b, c) * 100;
	}

	cout << result;
	return 0;
}
