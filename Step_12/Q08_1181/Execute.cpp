/*
문제
알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라 정렬하는 프로그램을 작성하시오.

길이가 짧은 것부터
길이가 같으면 사전 순으로
입력
첫째 줄에 단어의 개수 N이 주어진다. (1 ≤ N ≤ 20,000) 둘째 줄부터 N개의 줄에 걸쳐 알파벳 소문자로 이루어진 단어가 한 줄에 하나씩 주어진다. 주어지는 문자열의 길이는 50을 넘지 않는다.

출력
조건에 따라 정렬하여 단어들을 출력한다. 단, 같은 단어가 여러 번 입력된 경우에는 한 번씩만 출력한다.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool Compare(const string & w1, const string & w2)
{
	if(w1.size() < w2.size()) // 단어의 길이로 오름 차순
	{
		return true;
	}
	else
	{
		if(w1.size() == w2.size())
		{
			// 단어가 같을 경우
			if (w1 == w2)
				return false;

			// 사전 순으로 오름 차순 정렬 
			for (int i = 0; i < w1.size(); i++)
			{
				if (w1[i] < w2[i])
				{
					return true;
				}
				else
				{
					if(w1[i] == w2[i]) // 문자가 같다면 반복문 계속 진행
						continue;

					return false; // 문자가 같지 않을 경우
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

	int N; // 단어의 개수
	cin >> N;
	vector<string> words; // 입력받은 단어 배열
	for (int i = 0; i < N; i++)
	{
		string word;
		cin >> word;
		words.push_back(word);
	}

	sort(words.begin(), words.end(), Compare); // 정렬
	words.erase(unique(words.begin(), words.end()), words.end()); // 중복 제거 
	// 출력
	for(string word : words)
		cout << word << '\n';

	return 0;
}