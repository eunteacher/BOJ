/*
����
�׷� �ܾ�� �ܾ �����ϴ� ��� ���ڿ� ���ؼ�, �� ���ڰ� �����ؼ� ��Ÿ���� ��츸�� ���Ѵ�. ���� ���, ccazzzzbb�� c, a, z, b�� ��� �����ؼ� ��Ÿ����, kin�� k, i, n�� �����ؼ� ��Ÿ���� ������ �׷� �ܾ�������, aabbbccb�� b�� �������� ��Ÿ���� ������ �׷� �ܾ �ƴϴ�.

�ܾ� N���� �Է����� �޾� �׷� �ܾ��� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �ܾ��� ���� N�� ���´�. N�� 100���� �۰ų� ���� �ڿ����̴�. ��° �ٺ��� N���� �ٿ� �ܾ ���´�. �ܾ�� ���ĺ� �ҹ��ڷθ� �Ǿ��ְ� �ߺ����� ������, ���̴� �ִ� 100�̴�.

���
ù° �ٿ� �׷� �ܾ��� ������ ����Ѵ�.
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int count = 0; // �׷� �ܾ��� ����
	for (int i = 0; i < n; i++)
	{
		string word;
		cin >> word;

		int length = word.length();
		bool bGroup = true;

		for (int j = 0; j < length; j++)
		{
			int temp = j; // �ӽ� ��

			for (int k = j + 1; k < length; k++)
			{
				if (word[temp] == word[k])
				{
					// ���ڰ� ���� ���

					if ((k - temp) != 1)
					{
						// ���������� ���� ���, �� ���� �� ����
						// �׷� �ܾ �ƴϴ�.
						bGroup = false;
						break;
					} 
					else
					{
						// ������ ���
						temp = k; // ���� 3�� �̻��� ���ؼ� �ӽ� ���� ���� k ���� �־��ش�.
					}

				} // if a == words
			} // for k
			
			if (bGroup == false)
			{
				// �׷� �ܾ �ƴϸ� �ݺ����� �� �ʿ䰡 ����.
				continue;
			}
		} // for j

		if (bGroup == true)
		{
			// �ݺ����� ���´µ� true��� �׷� �ܾ� 
			count++;
		}
	} // for i

	cout << count;

	return 0;
}

