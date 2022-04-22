/*

*/
#include <iostream>
using namespace std;

int main()
{
	int n; // 테스트 케이스의 개수
	int r; // 반복 횟수
	char s[21]; // 문자열

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> r >> s;
		int index = 0;
		while (s[index] != NULL) // 모든 문자열 검사 
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