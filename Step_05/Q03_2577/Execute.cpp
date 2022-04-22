/*

*/

#include <iostream>
using namespace std;

// 각 자릿수의 값을 구하는 함수 
int GetRadixNum(int n, int radix)
{
	return (n / radix) % 10;
}

// 최대 자릿수 구하는 함수 
int MaxRadix(int n)
{
	int i = 1;

	// n이 i보다 작아지면 반복 중단 
	while (n >= i) 
	{
		i *= 10;
	}

	return i;
}

void Count(int arr[], int arrSize, int mul, int maxRadix)
{
	for (int i = 0; i < arrSize; i++) // 0 ~ 9 까지
	{
		for (int j = 1; j < maxRadix; j *= 10) //일의 자릿수부터 최대 자릿수만큼 확인 
		{
			if (i == GetRadixNum(mul, j))
			{
				arr[i] += 1;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력받을 a,b,c
	int a, b, c;
	cin >> a >> b >> c;
	int mul = a * b * c;

	// 0 ~ 9 가 횟수를 담을 배열
	int arr[10];
	for (int i = 0; i < 10; i++)
	{
		arr[i] = 0;
	}
	Count(arr, 10, mul, MaxRadix(mul));

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << '\n';
	}
	
	return 0;
}