/*
����
���ĺ� ��ҹ��ڷ� �� �ܾ �־�����, �� �ܾ�� ���� ���� ���� ���ĺ��� �������� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�. ��, �빮�ڿ� �ҹ��ڸ� �������� �ʴ´�.

�Է�
ù° �ٿ� ���ĺ� ��ҹ��ڷ� �̷���� �ܾ �־�����. �־����� �ܾ��� ���̴� 1,000,000�� ���� �ʴ´�.

���
ù° �ٿ� �� �ܾ�� ���� ���� ���� ���ĺ��� �빮�ڷ� ����Ѵ�. ��, ���� ���� ���� ���ĺ��� ���� �� �����ϴ� ��쿡�� ?�� ����Ѵ�.
*/
#include <iostream>
using namespace std;

int main()
{
	// 27 * 2
	int arr[26] = { 0, }; // A ~ Z, a ~ z �� ���� �迭

	char s[10000]; // �Է¹޴� �ܾ�
	cin >> s;
	int index = 0;
	while (s[index] != NULL)
	{
		char a = 'A';
		while (a <= 'z' + 1)
		{
			if (a == 'Z' + 1)
			{
				a = 'a';
			}

			if (s[index] == a)
			{
				// �빮��
				if (a < 'Z' + 1)
				{
					int k = a - 'A';
					arr[k]++;
				}

				// �ҹ���
				if (a > 'Z' + 1)
				{
					int k = a - 'a';
					arr[k]++;
				}
			} 
			a++;

		}// while (a < 'z' + 1)
		index++;
	}

	int max = arr[0];
	int maxIndex = 0;
	// ���� ���� ���� ���ĺ� Ž�� 
	for (int i = 0; i < 26; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			maxIndex = i;
		}
	}

	char result = 'A' + maxIndex;
	
	int k = 0;
	// �ߺ� üũ
	while (k < 26)
	{
		if (arr[k] == arr[maxIndex] && k != maxIndex)
		{
			result = '?';
		}
		k++;
	}

	cout << result;

	return 0;
}