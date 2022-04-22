/*
����
"OOXXOXXOOO"�� ���� OX������ ����� �ִ�. O�� ������ ���� ���̰�, X�� ������ Ʋ�� ���̴�. ������ ���� ��� �� ������ ������ �� �������� ���ӵ� O�� ������ �ȴ�. ���� ���, 10�� ������ ������ 3�� �ȴ�.

"OOXXOXXOOO"�� ������ 1+2+0+0+1+0+0+1+2+3 = 10���̴�.

OX������ ����� �־����� ��, ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ������ �־�����. �� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ְ�, ���̰� 0���� ũ�� 80���� ���� ���ڿ��� �־�����. ���ڿ��� O�� X������ �̷���� �ִ�.
*/

#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		char str[80] = { NULL, }; // ���ڿ� �ʱ�ȭ
		cin >> str;
		
		int index = 0;
		int score[80] = { 0, };

		while (str[index] != NULL) // ���ڿ� ������ �ݺ�
		{
			if (str[index] == 'O') // ���� 1�� �߰� 
			{
				score[index] = 1;
			}

			if (index != 0 && str[index] == 'O' && str[index - 1] == 'O')
			{
				score[index] += score[index - 1]; // �� �ε����� �ش��ϴ� ���� �� �ε����� �ش��ϴ� �� ����
			}

			index++;
		}

		// ��� ���� �ջ�
		int tatal = 0;
		for (int i = 0; i < 80; i++)
		{
			tatal += score[i];
		}
		cout << tatal << '\n';
	}

	return 0;
}