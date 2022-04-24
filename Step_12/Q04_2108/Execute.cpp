/*
수를 처리하는 것은 통계학에서 상당히 중요한 일이다. 통계학에서 N개의 수를 대표하는 기본 통계값에는 다음과 같은 것들이 있다. 단, N은 홀수라고 가정하자.

산술평균 : N개의 수들의 합을 N으로 나눈 값
중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
최빈값 : N개의 수들 중 가장 많이 나타나는 값
범위 : N개의 수들 중 최댓값과 최솟값의 차이
N개의 수가 주어졌을 때, 네 가지 기본 통계값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 단, N은 홀수이다. 그 다음 N개의 줄에는 정수들이 주어진다. 입력되는 정수의 절댓값은 4,000을 넘지 않는다.

출력
첫째 줄에는 산술평균을 출력한다. 소수점 이하 첫째 자리에서 반올림한 값을 출력한다.

둘째 줄에는 중앙값을 출력한다.

셋째 줄에는 최빈값을 출력한다. 여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.

넷째 줄에는 범위를 출력한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// 최빈값 구하기
int MaxCounting(int count[])
{
	int max = 0; // 최빈값
	
	for (int i = 0; i < 8001; i++)
	{
		// 최빈값 찾기 
		if (max < count[i])
			max = count[i];
	}

	// 같은 최빈값을 가진 값들 찾기
	vector<int> tmp;
	int idx = 0;
	for (int i = 0; i < 8001; i++)
	{
		if (count[i] == max)
		{
			tmp.push_back(i - 4000);
			idx++;
			if(idx > 1)
				break;
		}
	}

	if (tmp.size() > 1)
		return tmp[1];
	else
		return tmp[0];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 소수점 첫째 자리부터 반올림
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(1);

	// 수의 개수 입력
	int N;
	cin >> N;

	// N개의 정수
	vector<int> ans;
	int count[8001] = { 0, }; // 
	int total = 0;
	for (int i = 0; i < N; i++)
	{
		int tmp = 0;
		cin >> tmp;
		total += tmp;
		count[tmp + 4000]++; // 카운팅
		ans.push_back(tmp);
	}

	// 산술 평균
	float aver = (float)total / (float)N;
	cout << (int)roundf(aver) << '\n';
	// 중앙값 구하기
	sort(ans.begin(), ans.end());
	int center = ans[N / 2];
	cout << center << '\n';
	// 최빈값 구하기
	int maxCountVal = MaxCounting(count);
	cout << maxCountVal << '\n';
	// 범위 구하기
	// 정렬되어 있기 때문에 마지막 인덱스와 첫 번째 인덱스로 구하면 된다.
	int range = ans[N - 1] - ans[0];
	cout << range;

	return 0;
}