/*
����
N-Queen ������ ũ�Ⱑ N �� N�� ü���� ���� �� N���� ���� ������ �� ���� ���� �����̴�.

N�� �־����� ��, ���� ���� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� �־�����. (1 �� N < 15)

���
ù° �ٿ� �� N���� ���� ������ �� ���� ���� ����� ���� ����Ѵ�.
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
		if (board[i] == board[depth] || (depth - i) == abs(board[depth] - board[i])) // ���� ���� ���� �� �����Ƿ� ���� ���� ���Ѵ�.
		{
			// ���� �� Ȥ�� �밢���� �����ٸ� false�� ����
			return false; 
		}
	}

	// ���� �� ��찡 �ƴ϶�� true�� �����Ѵ�.
	return true;
}

void Counting(int depth)
{
	// ���� �� ���� ��ġ��� ����
	if (CanPut(board, depth) == false)
	{
		return;
	}

	if(depth == N) 
	{
		// ���̿� n�� ���� ���� ��� ī���� �����ϸ�, ��� �Լ��� �����.
		::count++;
		return;
	}
	else
	{
		// ���� ���� +1�� �ϸ鼭 ����Լ� ����
		for (int i = 1; i < N + 1; i++)
		{
			// depth ���� 0���� �����ϹǷ� +1
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