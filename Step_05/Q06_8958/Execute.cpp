/*
문제
"OOXXOXXOOO"와 같은 OX퀴즈의 결과가 있다. O는 문제를 맞은 것이고, X는 문제를 틀린 것이다. 문제를 맞은 경우 그 문제의 점수는 그 문제까지 연속된 O의 개수가 된다. 예를 들어, 10번 문제의 점수는 3이 된다.

"OOXXOXXOOO"의 점수는 1+2+0+0+1+0+0+1+2+3 = 10점이다.

OX퀴즈의 결과가 주어졌을 때, 점수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, 길이가 0보다 크고 80보다 작은 문자열이 주어진다. 문자열은 O와 X만으로 이루어져 있다.
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
		char str[80] = { NULL, }; // 문자열 초기화
		cin >> str;
		
		int index = 0;
		int score[80] = { 0, };

		while (str[index] != NULL) // 문자열 끝까지 반복
		{
			if (str[index] == 'O') // 점수 1점 추가 
			{
				score[index] = 1;
			}

			if (index != 0 && str[index] == 'O' && str[index - 1] == 'O')
			{
				score[index] += score[index - 1]; // 전 인덱스에 해당하는 값을 현 인덱스에 해당하는 값 더함
			}

			index++;
		}

		// 모든 점수 합산
		int tatal = 0;
		for (int i = 0; i < 80; i++)
		{
			tatal += score[i];
		}
		cout << tatal << '\n';
	}

	return 0;
}