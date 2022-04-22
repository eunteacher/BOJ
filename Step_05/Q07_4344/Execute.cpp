/*
문제
대학생 새내기들의 90%는 자신이 반에서 평균은 넘는다고 생각한다. 당신은 그들에게 슬픈 진실을 알려줘야 한다.

입력
첫째 줄에는 테스트 케이스의 개수 C가 주어진다.

둘째 줄부터 각 테스트 케이스마다 학생의 수 N(1 ≤ N ≤ 1000, N은 정수)이 첫 수로 주어지고, 이어서 N명의 점수가 주어진다. 점수는 0보다 크거나 같고, 100보다 작거나 같은 정수이다.

출력
각 케이스마다 한 줄씩 평균을 넘는 학생들의 비율을 반올림하여 소수점 셋째 자리까지 출력한다.
*/

#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int c; // 테스트 케이스
	cin >> c;

	for (int i = 0; i < c; i++)
	{
		int n; // 학생의 수 
		cin >> n;
		double* arr = new double[n]; // 점수를 담을 배열 
		double total = 0; // 총점
		// 값 입력 및 총점 계산
		for (int j = 0; j < n; j++)
		{
			cin >> arr[j];
			total += arr[j];
		}
		
		double aver = total / n; // 평균
		
		int count = 0;
		for (int j = 0; j < n; j++)
		{
			if (arr[j] > aver)
			{
				count += 1;
			}
		}
		cout << fixed; // 소숫점 고정
		cout.precision(3);
		cout << ((double)count / (double)n) * 100 << "%" << '\n';
	}

	return 0;
}