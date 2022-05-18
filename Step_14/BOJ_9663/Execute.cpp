/*
문제
N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.

N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. (1 ≤ N < 15)

출력
첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N = 0;
int board[15] = { 0, };
int count = 0;

bool CanPut(const int* board, int depth)
{
	for (int i = 1; i < depth; i++)
	{
		if (board[i] == board[depth] || (depth - i) == abs(board[depth] - board[i])) // 음수 값이 나올 수 있으므로 절대 값을 취한다.
		{
			// 같은 열 혹은 대각선에 놓였다면 false를 리턴
			return false; 
		}
	}

	// 위의 두 경우가 아니라면 true를 리턴한다.
	return true;
}

void Counting(int depth)
{
	// 놓을 수 없는 위치라면 리턴
	if (CanPut(board, depth) == false)
	{
		return;
	}

	if(depth == N) 
	{
		// 깊이와 n의 값이 같을 경우 카운팅 증가하며, 재귀 함수를 멈춘다.
		::count++;
		return;
	}
	else
	{
		// 깊이 값을 +1을 하면서 재귀함수 진행
		for (int i = 1; i < N + 1; i++)
		{
			// depth 값이 0부터 시작하므로 +1
			board[depth + 1] = i;
			Counting(depth + 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	Counting(0);
	cout << ::count;

	return 0;
}