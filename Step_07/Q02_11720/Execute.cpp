/*
문제
N개의 숫자가 공백 없이 쓰여있다. 이 숫자를 모두 합해서 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 숫자의 개수 N (1 ≤ N ≤ 100)이 주어진다. 둘째 줄에 숫자 N개가 공백없이 주어진다.

출력
입력으로 주어진 숫자 N개의 합을 출력한다.
*/
#include <iostream>
using namespace std;

int main()
{
	int n; // 입력 횟수
	//char s[101];

	cin >> n;
	//cin >> s;

	char* s2 = new char[n + 1];
	cin >> s2;
	int i = 0;
	int total = 0; // 총 합
	while (i < n)
	{
		// s[i] char형
		//total += int(s[i] - '0');
		total += int(s2[i] - '0'); 
		i++;
	}
	cout << total;

	delete[] s2;
	return 0;
}