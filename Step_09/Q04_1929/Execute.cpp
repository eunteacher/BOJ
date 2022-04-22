/*
문제
M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1 ≤ M ≤ N ≤ 1,000,000) M이상 N이하의 소수가 하나 이상 있는 입력만 주어진다.

출력
한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.
*/
#include <iostream>
#include "Timer.h"
using namespace std;

bool FindPrime(int n)
{
	if (n == 1)
		return false;

	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

// 에라토스테네스의 체는 소수(Prime Number)를 찾는 방법
// 대량의 소수들을 구해야할 때 아주 유용한 알고리즘으로 O(N ^ 1 / 2)의 시간복잡도를 갖는다.
// 소수란 약수가 오로지 1인 수이다. 즉, 1을 제외한 수의 배수가 되는 수는 소수가 아니다.
// 에라토스테네스의 체는 이러한 소수의 개념을 이용한 알고리즘이다.
// 임의의 수 n 까지의 소수를 구하고자 할 때 2부터 n의 제곱근까지 돌며 모든 배수들을 소수에서 제외시키는 방식이다.
void SievePrime(int m, int n)
{
	int* prime = new int[n + 1];
	//int prime[1000001]
	
	// 배열 초기화, 1은 합성수이므로 제외
	for (int i = 2; i < n + 1; i++)
		prime[i] = i;

	for (int i = 2; i <= n; i++)
	{
		// 값이 0인 원소는 소수가 아니므로 패스한다.
		if (prime[i] == 0)
			continue;

		// i의 배수를 전부 0으로 만든다.
		// i + i를 해서 2번째 배수부터 시작한다.
		for (int j = i + i; j <= n; j += i)
			prime[j] = 0;
	}

	for (m; m <= n; m++)
	{
		if (m == 1)
			continue;

		if (prime[m] != 0)
			cout << prime[m] << " ";
	}

	delete[] prime;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Timer t;

	int M, N;
	cin >> M >> N;
	cout << '\n';

	t.Start();
	for (M; M <= N; M++)
	{
		if (FindPrime(M) == true)
			cout << M << " ";
	}
	cout << '\n';
	t.End();
	cout << t.RunningTime() << '\n';

	cout << '\n';
	cin >> M >> N;

	t.Start();
	SievePrime(M, N);
	t.End();
	cout << '\n';
	cout << t.RunningTime() << '\n';

	// 내가 짠 코드가 더 빠르다. 쓰는 이유를 모르겠음.
	return 0;
}