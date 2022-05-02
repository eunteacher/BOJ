/*
����
��� A�� N�� ��¥ ����� �Ƿ���, N�� A�� ����̰�, A�� 1�� N�� �ƴϾ�� �Ѵ�. � �� N�� ��¥ ����� ��� �־��� ��, N�� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� ��¥ ����� ������ �־�����. �� ������ 50���� �۰ų� ���� �ڿ����̴�. ��° �ٿ��� N�� ��¥ ����� �־�����. 1,000,000���� �۰ų� ����, 2���� ũ�ų� ���� �ڿ����̰�, �ߺ����� �ʴ´�.

���
ù° �ٿ� N�� ����Ѵ�. N�� �׻� 32��Ʈ ��ȣ�ִ� ������ ǥ���� �� �ִ�.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N; // ����� ���� 
	vector<int> factors; // ���

	// ����� ������ ��� �Է�
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int tmp = 0;
		cin >> tmp;
		factors.push_back(tmp);
	}

	// �ּ� ��� * �ִ� ��� = �ڿ����� �̿�
	// ���� �� ù ��° ���ҿ� ������ ���Ҹ� ���ؼ� ���
	sort(factors.begin(), factors.end()); // ����
	cout << factors.front() * factors.back();

	return 0;
}