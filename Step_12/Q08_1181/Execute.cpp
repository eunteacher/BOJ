/*
����
���ĺ� �ҹ��ڷ� �̷���� N���� �ܾ ������ �Ʒ��� ���� ���ǿ� ���� �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

���̰� ª�� �ͺ���
���̰� ������ ���� ������
�Է�
ù° �ٿ� �ܾ��� ���� N�� �־�����. (1 �� N �� 20,000) ��° �ٺ��� N���� �ٿ� ���� ���ĺ� �ҹ��ڷ� �̷���� �ܾ �� �ٿ� �ϳ��� �־�����. �־����� ���ڿ��� ���̴� 50�� ���� �ʴ´�.

���
���ǿ� ���� �����Ͽ� �ܾ���� ����Ѵ�. ��, ���� �ܾ ���� �� �Էµ� ��쿡�� �� ������ ����Ѵ�.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool Compare(const string & w1, const string & w2)
{
	if(w1.size() < w2.size()) // �ܾ��� ���̷� ���� ����
	{
		return true;
	}
	else
	{
		if(w1.size() == w2.size())
		{
			// �ܾ ���� ���
			if (w1 == w2)
				return false;

			// ���� ������ ���� ���� ���� 
			for (int i = 0; i < w1.size(); i++)
			{
				if (w1[i] < w2[i])
				{
					return true;
				}
				else
				{
					if(w1[i] == w2[i]) // ���ڰ� ���ٸ� �ݺ��� ��� ����
						continue;

					return false; // ���ڰ� ���� ���� ���
				}
			}
		} // if(w1.size() == w2.size())
		return false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N; // �ܾ��� ����
	cin >> N;
	vector<string> words; // �Է¹��� �ܾ� �迭
	for (int i = 0; i < N; i++)
	{
		string word;
		cin >> word;
		words.push_back(word);
	}

	sort(words.begin(), words.end(), Compare); // ����
	words.erase(unique(words.begin(), words.end()), words.end()); // �ߺ� ���� 
	// ���
	for(string word : words)
		cout << word << '\n';

	return 0;
}