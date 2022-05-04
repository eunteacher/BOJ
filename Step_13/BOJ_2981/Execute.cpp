/*
����
Ʈ���� Ÿ�� �̵��ϴ� ����̴� ������ �˹��� �ް� �Ǿ���. ������ ����̰� ����ϴ� ȭ���� �ϳ��ϳ� ��� Ȯ���� ���̱� ������, �˹��ϴµ� ��û���� ���� �ð��� �ɸ���.

����̴� �ð��� ����� ���ؼ� ���� ������ �ϱ�� �ߴ�.

���� ��ó�� ���̴� ���� N���� ���̿� ���´�. �� ����, ���̿� ���� ���� M���� �������� ��, �������� ��� ���� �Ǵ� M�� ��� ã������ �Ѵ�. M�� 1���� Ŀ�� �Ѵ�.

N���� ���� �־����� ��, ������ M�� ��� ã�� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���̿� ���� ���� ���� N�� �־�����. (2 �� N �� 100)

���� �ٺ��� N�� �ٿ��� ���̿� ���� ���� �ϳ��� �־�����. �� ���� ��� 1���� ũ�ų� ����, 1,000,000,000���� �۰ų� ���� �ڿ����̴�. ���� ���� �� �� �̻� �־����� �ʴ´�.

�׻� M�� �ϳ� �̻� �����ϴ� ��츸 �Է����� �־�����.

���
ù° �ٿ� ������ M�� �������� �����Ͽ� ��� ����Ѵ�. �̶�, M�� �����ϴ� �����̾�� �Ѵ�.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// �� �� a, b�� �Է����� �ް�
// �� ���� �ִ� ������� ���ϴ� �Լ�
// ��Ŭ���� ȣ������ ����Ͽ� ����
// f(a,b) = gcd(a,b)�� �Ҷ�, a mod b = 0 �̶�� f(a,b) = b�̰�, a mod b = 0 �� �ƴ϶�� f(a,b) = f(b, a mod b)�� ����
int GCD(int a, int b)
{
	int mod = a % b;
	while(mod != 0)
	{
		a = b;
		b = mod;
		mod = a % b; // mod�� 0�� ������ �ݺ��� ����
	}

	return b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N; // ����
	cin >> N;
	vector<int> nums;
	// nums �Է�
	for (int i = 0; i < N; i++)
	{
		int tmp = 0;
		cin >> tmp;
		nums.push_back(tmp);
	}

	// ������ ���� ���� ���ؾ��ϱ� ������ �� ����
	sort(nums.begin(), nums.end()); 

	// 01. ������ �� �� ���ϱ�
	// 02. ���� ������ �ִ� ����� ���ϱ�
	// 03. ���� �ִ������� ��� ���
	vector<int> div; // ������ ���� ���� ���� ������ ����
	// 01
	for (int i = 1; i < N; i++)
		div.push_back(nums[i] - nums[i - 1]);
	// 02
	int max = GCD(div[1], div[0]); // �ִ�����
	for (int i = 1; i < div.size(); i++)
	{
		if (div[i] > max) max = GCD(div[i], max);
		else max = GCD(max, div[i]);
	}
	// 03
	vector<int> factors; // �ִ� ������� ����� ������ ����
	for (int i = 1; i * i <= max; i++)
	{
		if (i * i == max) factors.push_back(i);
		else if (max % i == 0)
		{
			factors.push_back(i);
			factors.push_back(max / i);
		}
	}

	// ���� �� ���
	sort(factors.begin(), factors.end());
	for (int factor : factors)
	{
		if (factor != 1)
			cout << factor << " ";
	}

	return 0;
}