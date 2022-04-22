/*
문제
지민이는 자신의 저택에서 MN개의 단위 정사각형으로 나누어져 있는 M×N 크기의 보드를 찾았다. 어떤 정사각형은 검은색으로 칠해져 있고, 나머지는 흰색으로 칠해져 있다. 지민이는 이 보드를 잘라서 8×8 크기의 체스판으로 만들려고 한다.

체스판은 검은색과 흰색이 번갈아서 칠해져 있어야 한다. 구체적으로, 각 칸이 검은색과 흰색 중 하나로 색칠되어 있고, 변을 공유하는 두 개의 사각형은 다른 색으로 칠해져 있어야 한다. 따라서 이 정의를 따르면 체스판을 색칠하는 경우는 두 가지뿐이다. 하나는 맨 왼쪽 위 칸이 흰색인 경우, 하나는 검은색인 경우이다.

보드가 체스판처럼 칠해져 있다는 보장이 없어서, 지민이는 8×8 크기의 체스판으로 잘라낸 후에 몇 개의 정사각형을 다시 칠해야겠다고 생각했다. 당연히 8*8 크기는 아무데서나 골라도 된다. 지민이가 다시 칠해야 하는 정사각형의 최소 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 M이 주어진다. N과 M은 8보다 크거나 같고, 50보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에는 보드의 각 행의 상태가 주어진다. B는 검은색이며, W는 흰색이다.

출력
첫째 줄에 지민이가 다시 칠해야 하는 정사각형 개수의 최솟값을 출력한다.
*/
#include <iostream>
#include <vector>
using namespace std;

int PaintBoard(vector<char> vecBoard, char a, char b, int w) // 체스판을 선형으로 담은 벡터  
{
	vector<int> vecMin;
	int len = (vecBoard.size() - (7 * w)) - 8; // 끝 원소에서 시작해서 8x8가 될 수 있는 최대 원소

	// 한 칸씩 당기면서 8x8 체스판을 검사한다.
	for (int i = 0; i <= len; i += w)
	{
		// 한 줄의 크기인 w를 초과하면 안되므로 i + (w - 8)까지 반복한다.
		for (int j = i; j <= i + (w - 8); j++)
		{
			int count = 0; // 변경한 횟수 
			// 세로 검사
			for (int k = j; k < j + (8 * w); k += w)
			{
				bool flag = false; // a와b를 번갈아가면서 검사할 bool 변수
				// 가로 검사, 8칸만
				for (int l = k; l < k + 8; l++)
				{
					// 한 줄을 검사할 때 항상 1번째 원소는 a가 나오므로 a먼저 검사
					if (a != vecBoard[l] && flag == false)
					{
						// a와 체스판이 다를 경우
						count++;
					}

					if (b != vecBoard[l] && flag == true)
					{
						// a를 검사하면 b를 검사
						// b와 체스판이 다를 경우
						count++;
					}

					flag = flag ? false : true; // flag가 true면 false로 false면 true
				}

				// 8칸씩부터 a와 b의 값을 바꾼다. 즉 줄바꿈이 일어나면 a와 b를 바꾼다.
				char temp = a;
				a = b;
				b = temp;
			}

			vecMin.push_back(count);
		}
	}

	// 최솟값 구하기
	int min = 0;
	if (vecMin.empty() == false)
	{
		min = vecMin[0];
		for (int i = 1; i < vecMin.size(); i++)
		{
			if (min > vecMin[i])
				min = vecMin[i];
		}
	}
	return min;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	char board[50][50];
	vector<char> vecBoard;
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
			vecBoard.push_back(board[i][j]); // 선형 자료를 위해 체스판을 벡터에 넣는다.
		}
	}

	// 바꾸는 방법
	// B -> W
	// W -> B
	// M과 N이 8이 넘는 경우 
	// 기준은 8x8에서 (0,0)의 점을 기준으로 한다.

	// W -> B
	char a = 'W';
	char b = 'B';
	int WtoB = PaintBoard(vecBoard, a, b, M);
	// B- > W
	a = 'B';
	b = 'W';
	int BtoW = PaintBoard(vecBoard, a, b, M);
	// 둘 중 더 작은 값 출력
	if (WtoB > BtoW)
		cout << BtoW;
	else
		cout << WtoB;

	return 0;
}