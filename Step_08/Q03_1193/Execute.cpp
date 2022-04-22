/*
문제
무한히 큰 배열에 다음과 같이 분수들이 적혀있다.

1/1	1/2	1/3	1/4	1/5	…
2/1	2/2	2/3	2/4	…	…
3/1	3/2	3/3	…	…	…
4/1	4/2	…	…	…	…
5/1	…	…	…	…	…
…	…	…	…	…	…
이와 같이 나열된 분수들을 1/1 → 1/2 → 2/1 → 3/1 → 2/2 → … 과 같은 지그재그 순서로 차례대로 1번, 2번, 3번, 4번, 5번, … 분수라고 하자.

X가 주어졌을 때, X번째 분수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 X(1 ≤ X ≤ 10,000,000)가 주어진다.

출력
첫째 줄에 분수를 출력한다.
*/
#include <iostream>
using namespace std;

int main()
{
	int input;
	cin >> input;

	int d = 1; // 분모
	int n = 1; // 분자

	bool x = false; // d == 1일때 false면 n++
	bool y = false; // n == 1일때 true면 d++
	bool z = false; // false면 n--, d++

	if (input == 1)
	{
		cout << n << "/" << d;
	}
	else
	{
		for (int i = 2; i < input + 1; i++)
		{
			if (d == n)
			{
				d++;
				if (n != 1)
				{
					if (z == false)
					{
						n--;
					}
					else
					{
						n++;
					}
				}
			}
			else if (d > n)
			{
				if (n == 1 && y == false)
				{
					n++;
					d--;
					y = true;
				}
				else if(n == 1 && y == true)
				{
					d++;
					y = false;
					z = true;
				}
				else
				{
					if (z == true)
					{
						n++;
						d--;
					}
					else
					{
						n--;
						d++;
					}

				}
			}
			else
			{
				if (d == 1 && x == false)
				{
					n++;
					x = true;
					z = false;
				}
				else if (d == 1 && x == true)
				{
					n--;
					d++;
					x = false;
				}
				else
				{
					if (z == true)
					{
						n++;
						d--;
					}
					else
					{
						n--;
						d++;
					}
				}
			}
		}
		cout << n << "/" << d;
	}

	

	return 0;
}

