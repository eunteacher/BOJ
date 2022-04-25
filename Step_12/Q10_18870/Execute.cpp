/*
����
������ ���� N���� ��ǥ X1, X2, ..., XN�� �ִ�. �� ��ǥ�� ��ǥ ������ �����Ϸ��� �Ѵ�.

Xi�� ��ǥ ������ ��� X'i�� ���� Xi > Xj�� �����ϴ� ���� �ٸ� ��ǥ�� ������ ���ƾ� �Ѵ�.

X1, X2, ..., XN�� ��ǥ ������ ������ ��� X'1, X'2, ..., X'N�� ����غ���.

�Է�
ù° �ٿ� N�� �־�����.

��° �ٿ��� ���� �� ĭ���� ���е� X1, X2, ..., XN�� �־�����.

���
ù° �ٿ� X'1, X'2, ..., X'N�� ���� �� ĭ���� �����ؼ� ����Ѵ�.

����
1 �� N �� 1,000,000
-10^9 �� Xi �� 10^9
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// ��ǥ ������ ��ŷ�� �ű�� �Ͱ� ���ٰ� ���� �ȴ�.

	int N; // ���� ����
	cin >> N;
	vector<int> nums; // ���� ������ ���� �迭
	vector<int> ranks; // ��ŷ �迭
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		nums.push_back(n);
		ranks.push_back(n);
	}

	// ��ŷ
	sort(ranks.begin(), ranks.end()); // ����
	ranks.erase(unique(ranks.begin(), ranks.end()), ranks.end()); // �ߺ� ����

	// ���
	// lower_bound(start, end, value)
	// -ranks.begin() : lower_bound(start, end, value)�� ��ȯ���� �ּҰ��̱� ������ ���� �ּҸ� ���ָ� �ε��� ���� ���´�. 
	for (int i = 0; i < N; i++)
		cout << lower_bound(ranks.begin(), ranks.end(), nums[i]) - ranks.begin() << " ";

	return 0;
}