/*
 * ���� ������ �Է¹޾� 90 ~ 100���� A, 80 ~ 89���� B, 70 ~ 79���� C, 60 ~ 69���� D, ������ ������ F�� ����ϴ� ���α׷��� �ۼ�
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