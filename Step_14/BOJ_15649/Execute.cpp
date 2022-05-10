/*
문제
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
입력
첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

출력
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다.
*/
#include <iostream>
#include <vector>
using namespace std;
/*
 * 깊이 우선 탐색
 * 입력 : 수열을 저장할 벡터, 방문 여부를 판단하는 벡터, 최댓값, 수열의 길이, 시작 숫자
 */
void DFS(vector<int> seq, vector<bool> visited, int n, int m, int start)
{
	// 출력
	if (start == m)
	{
		for (int i = 0; i < m; i++)
			cout << seq[i] << " ";
		cout << '\n';
		return;
	}

	// 방문하지 않은 숫자를 수열에 저장
	for (int i = 1; i < n + 1; i++)
	{
		if(visited[i] == false)
		{
			visited[i] = true; // 상태 변화
			seq[start] = i;
			DFS(seq, visited, n, m, start + 1); // 재귀 호출
			visited[i] = false; // 상태 복구
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 조건
	// 1부터 N까지 자연수 중 중복 없이 M개를 고른 수열
	int n, m;
	vector<int> seq;
	seq.assign(9, 0);
	vector<bool> visited;
	visited.assign(9, false);
	cin >> n >> m;
	DFS(seq, visited, n, m, 0);

	return 0;
}