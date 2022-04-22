/*
문제
두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 A와 B가 주어진다. (0 < A,B < 1010000)

출력
첫째 줄에 A+B를 출력한다.
*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string A, B;
	cin >> A >> B;

	string Sum = "";

	int lenA = A.length() - 1;
	int lenB = B.length() - 1;

	// 문자열의 길이를 똑같이 해준다.
	string temp = "";
	if (lenA > lenB)
	{
		for (int i = 0; i < lenA - lenB; i++)
		{
			temp += "0";
		}
		B = temp + B;
	}
	else
	{
		// lenA < lenB
		for (int i = 0; i < lenB - lenA; i++)
		{
			temp += "0";
		}
		A = temp + A;
	}

	int len = A.length();
	int a, b, sum;
	bool bCarry = false; // 올림 표시

	// 1의 자리부터 시작
	for (int i = len - 1; i >= 0; i--)
	{
		a = A[i] - '0';
		b = B[i] - '0';
		sum = a + b;

		if (bCarry == true)
		{
			sum += 1;
			bCarry = false;
		}

		// 10 이상이면 앞 자리에 1 올려줘야된다.
		if (sum > 9)
		{
			Sum += to_string(sum % 10);
			bCarry = true;
		}
		else
		{
			Sum += to_string(sum);
		}
	}

	if (bCarry == true)
	{
		Sum += "1";
	}

	reverse(Sum.begin(), Sum.end());

	cout << Sum;

	return 0;
}