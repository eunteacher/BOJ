/*
 * 시험 점수를 입력받아 90 ~ 100점은 A, 80 ~ 89점은 B, 70 ~ 79점은 C, 60 ~ 69점은 D, 나머지 점수는 F를 출력하는 프로그램을 작성
 */
#include <iostream>
using namespace std;

int main()
{
	int score;
	cin >> score;

	if (score >= 90 && score <= 100)
	{
		cout << "A";
	}
	else if (score >= 80 && score <= 89)
	{
		cout << "B";

	}
	else if (score >= 70 && score <= 79)
	{
		cout << "C";

	}
	else if (score >= 60 && score <= 69)
	{
		cout << "D";

	}
	else
	{
		cout << "F";
	}
	return 0;
}