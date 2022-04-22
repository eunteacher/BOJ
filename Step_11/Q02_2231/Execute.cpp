/*
문제
어떤 자연수 N이 있을 때, 그 자연수 N의 분해합은 N과 N을 이루는 각 자리수의 합을 의미한다. 어떤 자연수 M의 분해합이 N인 경우, M을 N의 생성자라 한다. 예를 들어, 245의 분해합은 256(=245+2+4+5)이 된다. 따라서 245는 256의 생성자가 된다. 물론, 어떤 자연수의 경우에는 생성자가 없을 수도 있다. 반대로, 생성자가 여러 개인 자연수도 있을 수 있다.

자연수 N이 주어졌을 때, N의 가장 작은 생성자를 구해내는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 N(1 ≤ N ≤ 1,000,000)이 주어진다.

출력
첫째 줄에 답을 출력한다. 생성자가 없는 경우에는 0을 출력한다.
*/
#include <iostream>
#include <vector>
using namespace std;

int GetDigit(int n)
{
	int count = 1;
	while (n > 1)
	{
		n /= 10;
		count *= 10;
	}
	return count;
}

int GetNum(int n, int digit)
{
	return (n / digit) % 10;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> c; // 생성자를 담을 배열

	for (int i = 1; i <= 1000000; i++)
	{
		int maxDigit = GetDigit(i); // 최대 자릿수
		int sum = 0; // 합
		for (int j = 1; j <= maxDigit; j *= 10)
		{
			sum += GetNum(i, j); // 각 자릿수의 합
		}
		sum += i; // 자기 자신 합
		if (sum == N) // 생성자
			c.push_back(i);
	}

	if (c.empty() == true)
	{
		// 비어 있으면 0 출력
		cout << 0;
		return 0;
	}
	else
	{
		// 생성자 중 최솟값 찾기 
		int min = c[0];
		for (int i = 1; i < c.size(); i++)
		{
			if (min > c[i])
				min = c[i];
		}
		cout << min;
	}

	return 0;
}