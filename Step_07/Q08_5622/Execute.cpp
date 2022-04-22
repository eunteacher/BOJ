/*
문제
상근이의 할머니는 아래 그림과 같이 오래된 다이얼 전화기를 사용한다.

전화를 걸고 싶은 번호가 있다면, 숫자를 하나를 누른 다음에 금속 핀이 있는 곳 까지 시계방향으로 돌려야 한다. 숫자를 하나 누르면 다이얼이 처음 위치로 돌아가고, 다음 숫자를 누르려면 다이얼을 처음 위치에서 다시 돌려야 한다.

숫자 1을 걸려면 총 2초가 필요하다. 1보다 큰 수를 거는데 걸리는 시간은 이보다 더 걸리며, 한 칸 옆에 있는 숫자를 걸기 위해선 1초씩 더 걸린다.

상근이의 할머니는 전화 번호를 각 숫자에 해당하는 문자로 외운다. 즉, 어떤 단어를 걸 때, 각 알파벳에 해당하는 숫자를 걸면 된다. 예를 들어, UNUCIC는 868242와 같다.

할머니가 외운 단어가 주어졌을 때, 이 전화를 걸기 위해서 필요한 최소 시간을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 알파벳 대문자로 이루어진 단어가 주어진다. 단어의 길이는 2보다 크거나 같고, 15보다 작거나 같다.
*/
#include <iostream>
using namespace std;

int main()
{
	char s[16]; // 입력 받을 단어
	int length = 0; // 단어의 길이 
	do
	{
		cin >> s;
		while (s[length] != NULL)
		{
			length++;
		}

	} while ((length >= 2 || length <= 15) == false);

	int* dials = new int[length]; // 단어를 숫자로 변환하고 담을 배열

	for (int i = 0; i < length; i++)
	{
		if (s[i] >= 'P' && s[i] <= 'S')
		{
			// 숫자 7
			dials[i] = 7;
		}
		else if (s[i] >= 'W' && s[i] <= 'Z')
		{
			// 숫자 9
			dials[i] = 9;
		}
		else
		{
			if (s[i] >= 'A' && s[i] <= 'O')
			{
				// 숫자 2,3,4,5,6
				dials[i] = ((s[i] - 'A') / 3) + 2;
			}
			else if(s[i] >= 'T' && s[i] <= 'V')
			{
				// 숫자 8
				dials[i] = 8;
			}
		}
	}

	// 시간 계산
	int* times = new int[length]; // 각각 걸리는 시간을 담을 배열
	for (int i = 0; i < length; i++)
	{
		int start = 1; // 시작, 숫자 1부터 시작
		int time = 2; // 숫자 1까지 걸리는 시간이 2초니까 값을 2
		while (start < dials[i])
		{
			start++;
			time++;
		}
		times[i] = time;
	}

	int total = 0; // 총 걸린 시간
	for (int i = 0; i < length; i++)
	{
		total += times[i];
	}
	
	cout << total;

	delete[] times;
	delete[] dials;

	return 0;
}