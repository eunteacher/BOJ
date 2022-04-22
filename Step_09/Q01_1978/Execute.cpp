/*
문제
주어진 수 N개 중에서 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오.

입력
첫 줄에 수의 개수 N이 주어진다. N은 100이하이다. 다음으로 N개의 수가 주어지는데 수는 1,000 이하의 자연수이다.

출력
주어진 수들 중 소수의 개수를 출력한다.
*/
#include <iostream>
using namespace std;

bool FindPrimeNum(int num)
{
	// 1은 소수가 아니다.
	if (num == 1)
		return false;
	
	// n의 제곱근 이하의 어떤 수로도 나누어떨어지지 않는다면 소수다.
	// num의 루트함수를 사용하지 않고, i의 제곱을 사용한다.
	for (int i = 2; i * i <= num; i++)
	{
		// 나누어 떨어지면 소수가 아니다.
		if (num % i == 0)
			return false;
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;

	int arr[101] = { 0, };
	int primeNum = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (FindPrimeNum(arr[i]) == true)
			primeNum++;
	}

	cout << primeNum;

	return 0;
}