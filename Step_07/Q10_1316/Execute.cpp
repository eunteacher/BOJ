/*
문제
그룹 단어란 단어에 존재하는 모든 문자에 대해서, 각 문자가 연속해서 나타나는 경우만을 말한다. 예를 들면, ccazzzzbb는 c, a, z, b가 모두 연속해서 나타나고, kin도 k, i, n이 연속해서 나타나기 때문에 그룹 단어이지만, aabbbccb는 b가 떨어져서 나타나기 때문에 그룹 단어가 아니다.

단어 N개를 입력으로 받아 그룹 단어의 개수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 단어의 개수 N이 들어온다. N은 100보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에 단어가 들어온다. 단어는 알파벳 소문자로만 되어있고 중복되지 않으며, 길이는 최대 100이다.

출력
첫째 줄에 그룹 단어의 개수를 출력한다.
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int count = 0; // 그룹 단어의 개수
	for (int i = 0; i < n; i++)
	{
		string word;
		cin >> word;

		int length = word.length();
		bool bGroup = true;

		for (int j = 0; j < length; j++)
		{
			int temp = j; // 임시 값

			for (int k = j + 1; k < length; k++)
			{
				if (word[temp] == word[k])
				{
					// 문자가 같은 경우

					if ((k - temp) != 1)
					{
						// 연속적이지 않을 경우, 즉 같은 값 존재
						// 그룹 단어가 아니다.
						bGroup = false;
						break;
					} 
					else
					{
						// 연속일 경우
						temp = k; // 연속 3개 이상을 위해서 임시 값의 현재 k 값을 넣어준다.
					}

				} // if a == words
			} // for k
			
			if (bGroup == false)
			{
				// 그룹 단어가 아니면 반복문을 할 필요가 없다.
				continue;
			}
		} // for j

		if (bGroup == true)
		{
			// 반복문을 끝냈는데 true라면 그룹 단어 
			count++;
		}
	} // for i

	cout << count;

	return 0;
}

