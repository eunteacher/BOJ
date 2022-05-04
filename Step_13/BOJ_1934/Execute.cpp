/*
문제
두 자연수 A와 B에 대해서, A의 배수이면서 B의 배수인 자연수를 A와 B의 공배수라고 한다. 이런 공배수 중에서 가장 작은 수를 최소공배수라고 한다. 예를 들어, 6과 15의 공배수는 30, 60, 90등이 있으며, 최소 공배수는 30이다.

두 자연수 A와 B가 주어졌을 때, A와 B의 최소공배수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 T(1 ≤ T ≤ 1,000)가 주어진다. 둘째 줄부터 T개의 줄에 걸쳐서 A와 B가 주어진다. (1 ≤ A, B ≤ 45,000)

출력
첫째 줄부터 T개의 줄에 A와 B의 최소공배수를 입력받은 순서대로 한 줄에 하나씩 출력한다.
*/
#include <iostream>
using namespace std;

// 최대 공약수를 구하는 함수
// 유클리드 호제법 사용
// f(a,b) = gcd(a,b)라 할때, a mod b = 0 이라면 f(a,b) = b이고, a mod b = 0 가 아니라면 f(a,b) = f(b, a mod b)가 성립
// 재귀 함수 이용
int GCD(int a, int b)
{
	int mod = a % b;

	if (a % b == 0)	return b;
	else return GCD(b, a % b);
}
// 최소 공배수 구하기
// a * b = GCD(a,b) * LCM(a,b)
int LCM(int a, int b)
{
	return (a * b) / GCD(a, b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	int a, b;
	for(int i=0; i<N;i++)
	{
		cin >> a >> b;
		cout << LCM(a, b) << '\n';
	}

	return 0;
}