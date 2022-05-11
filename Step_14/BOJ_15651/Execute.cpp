/*
문제
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

1부터 N까지 자연수 중에서 M개를 고른 수열
같은 수를 여러 번 골라도 된다.
입력
첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 7)

출력
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다.
*/
#include <iostream>
#include <vector>
using namespace std;

int n, m; // 입력 값
vector<int> seq; // 수열을 저장할 벡터 

void DFS(int start)
{
	// 출력 및 재귀 함수 탈출
	if (start == m)
	{
		for (int i = 0; i < m; i++)
			cout << seq[i] << " ";

		cout << '\n';
		return;
	}

	// 1 ~ n까지 반복문을 수행하며
	// 조건에 맞는 수를 저장
	for (int i = 1; i < n + 1; i++)
	{
		seq[start] = i;
		DFS(start + 1);
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 벡터 초기화
	seq.assign(8, 0);
	// 입력
	cin >> n >> m;
	DFS(0);

	return 0;
}
