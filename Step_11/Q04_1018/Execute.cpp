/*
����
�����̴� �ڽ��� ���ÿ��� MN���� ���� ���簢������ �������� �ִ� M��N ũ���� ���带 ã�Ҵ�. � ���簢���� ���������� ĥ���� �ְ�, �������� ������� ĥ���� �ִ�. �����̴� �� ���带 �߶� 8��8 ũ���� ü�������� ������� �Ѵ�.

ü������ �������� ����� �����Ƽ� ĥ���� �־�� �Ѵ�. ��ü������, �� ĭ�� �������� ��� �� �ϳ��� ��ĥ�Ǿ� �ְ�, ���� �����ϴ� �� ���� �簢���� �ٸ� ������ ĥ���� �־�� �Ѵ�. ���� �� ���Ǹ� ������ ü������ ��ĥ�ϴ� ���� �� �������̴�. �ϳ��� �� ���� �� ĭ�� ����� ���, �ϳ��� �������� ����̴�.

���尡 ü����ó�� ĥ���� �ִٴ� ������ ���, �����̴� 8��8 ũ���� ü�������� �߶� �Ŀ� �� ���� ���簢���� �ٽ� ĥ�ؾ߰ڴٰ� �����ߴ�. �翬�� 8*8 ũ��� �ƹ������� ��� �ȴ�. �����̰� �ٽ� ĥ�ؾ� �ϴ� ���簢���� �ּ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� M�� �־�����. N�� M�� 8���� ũ�ų� ����, 50���� �۰ų� ���� �ڿ����̴�. ��° �ٺ��� N���� �ٿ��� ������ �� ���� ���°� �־�����. B�� �������̸�, W�� ����̴�.

���
ù° �ٿ� �����̰� �ٽ� ĥ�ؾ� �ϴ� ���簢�� ������ �ּڰ��� ����Ѵ�.
*/
#include <iostream>
#include <vector>
using namespace std;

int PaintBoard(vector<char> vecBoard, char a, char b, int w) // ü������ �������� ���� ����  
{
	vector<int> vecMin;
	int len = (vecBoard.size() - (7 * w)) - 8; // �� ���ҿ��� �����ؼ� 8x8�� �� �� �ִ� �ִ� ����

	// �� ĭ�� ���鼭 8x8 ü������ �˻��Ѵ�.
	for (int i = 0; i <= len; i += w)
	{
		// �� ���� ũ���� w�� �ʰ��ϸ� �ȵǹǷ� i + (w - 8)���� �ݺ��Ѵ�.
		for (int j = i; j <= i + (w - 8); j++)
		{
			int count = 0; // ������ Ƚ�� 
			// ���� �˻�
			for (int k = j; k < j + (8 * w); k += w)
			{
				bool flag = false; // a��b�� �����ư��鼭 �˻��� bool ����
				// ���� �˻�, 8ĭ��
				for (int l = k; l < k + 8; l++)
				{
					// �� ���� �˻��� �� �׻� 1��° ���Ҵ� a�� �����Ƿ� a���� �˻�
					if (a != vecBoard[l] && flag == false)
					{
						// a�� ü������ �ٸ� ���
						count++;
					}

					if (b != vecBoard[l] && flag == true)
					{
						// a�� �˻��ϸ� b�� �˻�
						// b�� ü������ �ٸ� ���
						count++;
					}

					flag = flag ? false : true; // flag�� true�� false�� false�� true
				}

				// 8ĭ������ a�� b�� ���� �ٲ۴�. �� �ٹٲ��� �Ͼ�� a�� b�� �ٲ۴�.
				char temp = a;
				a = b;
				b = temp;
			}

			vecMin.push_back(count);
		}
	}

	// �ּڰ� ���ϱ�
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
			vecBoard.push_back(board[i][j]); // ���� �ڷḦ ���� ü������ ���Ϳ� �ִ´�.
		}
	}

	// �ٲٴ� ���
	// B -> W
	// W -> B
	// M�� N�� 8�� �Ѵ� ��� 
	// ������ 8x8���� (0,0)�� ���� �������� �Ѵ�.

	// W -> B
	char a = 'W';
	char b = 'B';
	int WtoB = PaintBoard(vecBoard, a, b, M);
	// B- > W
	a = 'B';
	b = 'W';
	int BtoW = PaintBoard(vecBoard, a, b, M);
	// �� �� �� ���� �� ���
	if (WtoB > BtoW)
		cout << BtoW;
	else
		cout << WtoB;

	return 0;
}