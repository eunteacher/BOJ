/*
문제
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 10,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 수가 주어진다. 이 수는 10,000보다 작거나 같은 자연수이다.

출력
첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.
*/
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N; // 배열의 크기
	int count[10001] = { 0, };
	int max = 0; // 입력받은 수 중 최댓값

	// input
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int tmp = 0;
		cin >> tmp;
		count[tmp]++; // 카운팅
		// 입력 받은 수 중 최댓값 구하기
		if (tmp > max)
			max = tmp;
	}

	for (int i = 1; i < max + 1; i++)
	{
		// 누적 및 정렬 후 출력
		while (count[i]-- > 0)
			cout << i << '\n';
	}

	return 0;
}