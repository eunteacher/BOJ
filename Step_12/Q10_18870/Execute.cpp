/*
문제
수직선 위에 N개의 좌표 X1, X2, ..., XN이 있다. 이 좌표에 좌표 압축을 적용하려고 한다.

Xi를 좌표 압축한 결과 X'i의 값은 Xi > Xj를 만족하는 서로 다른 좌표의 개수와 같아야 한다.

X1, X2, ..., XN에 좌표 압축을 적용한 결과 X'1, X'2, ..., X'N를 출력해보자.

입력
첫째 줄에 N이 주어진다.

둘째 줄에는 공백 한 칸으로 구분된 X1, X2, ..., XN이 주어진다.

출력
첫째 줄에 X'1, X'2, ..., X'N을 공백 한 칸으로 구분해서 출력한다.

제한
1 ≤ N ≤ 1,000,000
-10^9 ≤ Xi ≤ 10^9
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 좌표 압축은 랭킹을 매기는 것과 같다고 보면 된다.

	int N; // 수의 개수
	cin >> N;
	vector<int> nums; // 수를 저장할 원본 배열
	vector<int> ranks; // 랭킹 배열
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		nums.push_back(n);
		ranks.push_back(n);
	}

	// 랭킹
	sort(ranks.begin(), ranks.end()); // 정렬
	ranks.erase(unique(ranks.begin(), ranks.end()), ranks.end()); // 중복 제거

	// 출력
	// lower_bound(start, end, value)
	// -ranks.begin() : lower_bound(start, end, value)의 반환값은 주소값이기 떄문에 시작 주소를 뺴주면 인덱스 값이 나온다. 
	for (int i = 0; i < N; i++)
		cout << lower_bound(ranks.begin(), ranks.end(), nums[i]) - ranks.begin() << " ";

	return 0;
}