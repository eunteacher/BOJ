/*
문제
두 개의 자연수를 입력받아 최대 공약수와 최소 공배수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에는 두 개의 자연수가 주어진다. 이 둘은 10,000이하의 자연수이며 사이에 한 칸의 공백이 주어진다.

출력
첫째 줄에는 입력으로 주어진 두 수의 최대공약수를, 둘째 줄에는 입력으로 주어진 두 수의 최소 공배수를 출력한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 최대 공약수 구하기 - 반복문
int GetGCD(int a, int b)
{
	// 1에서 부터 최댓값까지 모든 경우의 수 검사하여 최댓값 반환
	//int max = 0;
	//int range = min(a, b);
	//for (int i = 1; i <= range; i++)
	//{
	//	if (a % i == 0 && b % i == 0)
	//		max = i;
	//}
	// return max;

	// 유클리드 호제법 이용
	// f(a,b) = gcd(a,b)라 할때, a mod b = 0 이라면 f(a,b) = b이고, a mod b = 0 가 아니라면 f(a,b) = f(b, a mod b)가 성립 
	//int mod = a % b;
	//while (mod > 0)
	//{
	//	a = b;
	//	b = mod;
	//	mod = a % b;
	//}

	if (a % b == 0)
		return b;
	else
		return GetGCD(b, a % b);

	return b;
}
// 최대 공약수 구하기 - 재귀함수
int GetGCD2(int a, int b)
{
	if (a % b == 0)
		return b;
	else
		return GetGCD2(b, a % b);
}
// 최소 공배수 구하기
// a * b = GCD(a,b) * LCM(a,b)
int GetLCM(int a, int b)
{
	return (a * b) / GetGCD(a, b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	cin >> a >> b;
	cout << GetGCD(a, b) << '\n';
	//cout << GetGCD2(a, b) << '\n';
	cout << GetLCM(a, b);

	return 0;
}