#include <iostream>
using namespace std;

int main()
{
	// 분자가 홀수번째 대각선에서 아래로 증가, 짝수번째 대각선에서 위로 증가 
	// 분모는 분자의 반대 방향으로 이루어져 있어서, 분모 == (i + 1) - 분자 
	int N;
	cin >> N;

	int i = 1;  // 대각선의 수
	while (N > i)
	{
		// i번째 대각선에 N번째 원소가 존재한다.
		N -= i;
		i++;
	}

	// 분자를 먼저 생각하기
	if (i % 2 == 0)
	{
		//짝수
		cout << N << "/" << i + 1 - N;
	}
	else
	{
		// 홀수
		cout << i + 1 - N << "/" << N;
	}

	return 0;
}