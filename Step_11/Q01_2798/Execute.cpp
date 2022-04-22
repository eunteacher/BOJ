/*
문제
카지노에서 제일 인기 있는 게임 블랙잭의 규칙은 상당히 쉽다. 카드의 합이 21을 넘지 않는 한도 내에서, 카드의 합을 최대한 크게 만드는 게임이다. 블랙잭은 카지노마다 다양한 규정이 있다.

한국 최고의 블랙잭 고수 김정인은 새로운 블랙잭 규칙을 만들어 상근, 창영이와 게임하려고 한다.

김정인 버전의 블랙잭에서 각 카드에는 양의 정수가 쓰여 있다. 그 다음, 딜러는 N장의 카드를 모두 숫자가 보이도록 바닥에 놓는다. 그런 후에 딜러는 숫자 M을 크게 외친다.

이제 플레이어는 제한된 시간 안에 N장의 카드 중에서 3장의 카드를 골라야 한다. 블랙잭 변형 게임이기 때문에, 플레이어가 고른 카드의 합은 M을 넘지 않으면서 M과 최대한 가깝게 만들어야 한다.

N장의 카드에 써져 있는 숫자가 주어졌을 때, M을 넘지 않으면서 M에 최대한 가까운 카드 3장의 합을 구해 출력하시오.

입력
첫째 줄에 카드의 개수 N(3 ≤ N ≤ 100)과 M(10 ≤ M ≤ 300,000)이 주어진다. 둘째 줄에는 카드에 쓰여 있는 수가 주어지며, 이 값은 100,000을 넘지 않는 양의 정수이다.

합이 M을 넘지 않는 카드 3장을 찾을 수 있는 경우만 입력으로 주어진다.

출력
첫째 줄에 M을 넘지 않으면서 M에 최대한 가까운 카드 3장의 합을 출력한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> cards;
	for (int i = 0; i < N; i++) // 5개의 숫자 입력 받기 
	{
		int x = 0;
		cin >> x;
		cards.push_back(x);
	}
	int len = cards.size();

	// 조합을 위한 벡터 선언
	vector<int> temp;
	int c = 3; // 뽑는 카드 수
	for (int i = 0; i < len; i++)
	{
		if (i >= c)
			temp.push_back(0); // c ~ N까지는 0을 대입
		else 
			temp.push_back(1); // 최대 0 ~ c 까지는 1을 대입
	}

	vector<int> sum; // N개 중 3개 뽑은 숫자를 다 더해 넣을 벡터 
	sort(cards.begin(), cards.end()); // 카드 정렬
	// 3개씩 뽑아서 더한 수를 sum에 넣는다.
	do
	{
		int x = 0;
		for (int i = 0; i < len; ++i)
		{
			if (temp[i] == 1)
				x += cards[i]; 
		}
		sum.push_back(x);
	} while (prev_permutation(temp.begin(), temp.end()));

	int min = M - sum[0]; // 제일 작은 값을 뽑기 위한 변수 
	int minIndex = 0; // 제일 작은 값의 인덱스
	for (int i = 1; i < sum.size(); i++)
	{
		if (sum[i] > M)
			continue;

		if (min > M - sum[i])
		{
			min = M - sum[i];
			minIndex = i;
		}
	}

	cout << sum[minIndex];
	return 0;
}