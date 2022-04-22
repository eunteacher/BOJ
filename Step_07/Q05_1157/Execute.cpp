/*
문제
알파벳 대소문자로 된 단어가 주어지면, 이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오. 단, 대문자와 소문자를 구분하지 않는다.

입력
첫째 줄에 알파벳 대소문자로 이루어진 단어가 주어진다. 주어지는 단어의 길이는 1,000,000을 넘지 않는다.

출력
첫째 줄에 이 단어에서 가장 많이 사용된 알파벳을 대문자로 출력한다. 단, 가장 많이 사용된 알파벳이 여러 개 존재하는 경우에는 ?를 출력한다.
*/
#include <iostream>
using namespace std;

int main()
{
	// 27 * 2
	int arr[26] = { 0, }; // A ~ Z, a ~ z 를 담을 배열

	char s[10000]; // 입력받는 단어
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
				// 대문자
				if (a < 'Z' + 1)
				{
					int k = a - 'A';
					arr[k]++;
				}

				// 소문자
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
	// 제일 많이 나온 알파벳 탐색 
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
	// 중복 체크
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