/*

*/
#include <iostream>
using namespace std;

int main()
{
	int n; // �׽�Ʈ ���̽��� ����
	int r; // �ݺ� Ƚ��
	char s[21]; // ���ڿ�

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> r >> s;
		int index = 0;
		while (s[index] != NULL) // ��� ���ڿ� �˻� 
		{
			for (int j = 0; j < r; j++)
			{
				cout << s[index];
			}
			index++;
		}
		cout << '\n';
	}

	return 0;
}