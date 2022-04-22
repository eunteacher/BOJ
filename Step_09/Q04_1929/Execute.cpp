/*
����
M�̻� N������ �Ҽ��� ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �ڿ��� M�� N�� �� ĭ�� ���̿� �ΰ� �־�����. (1 �� M �� N �� 1,000,000) M�̻� N������ �Ҽ��� �ϳ� �̻� �ִ� �Է¸� �־�����.

���
�� �ٿ� �ϳ���, �����ϴ� ������� �Ҽ��� ����Ѵ�.
*/
#include <iostream>
#include "Timer.h"
using namespace std;

bool FindPrime(int n)
{
	if (n == 1)
		return false;

	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

// �����佺�׳׽��� ü�� �Ҽ�(Prime Number)�� ã�� ���
// �뷮�� �Ҽ����� ���ؾ��� �� ���� ������ �˰������� O(N ^ 1 / 2)�� �ð����⵵�� ���´�.
// �Ҽ��� ����� ������ 1�� ���̴�. ��, 1�� ������ ���� ����� �Ǵ� ���� �Ҽ��� �ƴϴ�.
// �����佺�׳׽��� ü�� �̷��� �Ҽ��� ������ �̿��� �˰����̴�.
// ������ �� n ������ �Ҽ��� ���ϰ��� �� �� 2���� n�� �����ٱ��� ���� ��� ������� �Ҽ����� ���ܽ�Ű�� ����̴�.
void SievePrime(int m, int n)
{
	int* prime = new int[n + 1];
	//int prime[1000001]
	
	// �迭 �ʱ�ȭ, 1�� �ռ����̹Ƿ� ����
	for (int i = 2; i < n + 1; i++)
		prime[i] = i;

	for (int i = 2; i <= n; i++)
	{
		// ���� 0�� ���Ҵ� �Ҽ��� �ƴϹǷ� �н��Ѵ�.
		if (prime[i] == 0)
			continue;

		// i�� ����� ���� 0���� �����.
		// i + i�� �ؼ� 2��° ������� �����Ѵ�.
		for (int j = i + i; j <= n; j += i)
			prime[j] = 0;
	}

	for (m; m <= n; m++)
	{
		if (m == 1)
			continue;

		if (prime[m] != 0)
			cout << prime[m] << " ";
	}

	delete[] prime;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Timer t;

	int M, N;
	cin >> M >> N;
	cout << '\n';

	t.Start();
	for (M; M <= N; M++)
	{
		if (FindPrime(M) == true)
			cout << M << " ";
	}
	cout << '\n';
	t.End();
	cout << t.RunningTime() << '\n';

	cout << '\n';
	cin >> M >> N;

	t.Start();
	SievePrime(M, N);
	t.End();
	cout << '\n';
	cout << t.RunningTime() << '\n';

	// ���� § �ڵ尡 �� ������. ���� ������ �𸣰���.
	return 0;
}