/*
����
����̴� â���� �� N���� �߰��ߴ�. ����̴� ������ ���� �տ� �ִ� ���� �ڿ� �ִ� ���� ���ϵ��� �ٴڿ� �������Ҵ�.

����̴� ù ��° ���� ������ �����߰�, ������ ���� ���� ���ư��ٴ� ����� �߰��ߴ�. ������ ���� ù ��° �� ���� ������ ���ư��⵵ �߰�, ������ ���ư��⵵ �ߴ�. �̷��� ���� ������ ���� ù ��° ���� �� ���� ������, ������ ���� �� ���� ������ �ñ�������.

���� �������� �־�����. �̶�, ù ��° ���� �� ���� ������, ������ ���� �� ���� ���ư����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� ���� N�� �־�����. (3 �� N �� 100)

���� �ٿ��� ���� �������� ����̰� �ٴڿ� ���� ������� �־�����. �������� 1�� 1000�� �����ϴ� ������ �ڿ����̴�.

���
����� �� N-1���� �ؾ� �Ѵ�. ù ��° ���� ������ ������ ���� ���ؼ�, ù ��° ���� �� ���� ������ �� ���� �� ���� ������ ��� �м� ���� A/B�� ����Ѵ�.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ���ڸ� �Է¹޾� �� ������ ������� ������ ���͸� ��ȯ
vector<int> GetFactor(int n)
{
	vector<int> tmp;

	for (int i = 1; i * i <= n; i++)
	{
		if (i * i == n)
			tmp.push_back(i);
		else if(n % i == 0)
		{
			tmp.push_back(i);
			tmp.push_back(n / i);
		}
	}

	// ����
	sort(tmp.begin(), tmp.end());

	return tmp;
}

// �Է¹��� ���Ϳ� n�� �����ϴ��� �Ǵ�
// ���� Ž�� ���
bool IsExist(vector<int> vec, int n)
{
	int left = 0;
	int right = vec.size() - 1;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (vec[mid] == n) return true;
		else if (vec[mid] < n) left = mid + 1;
		else if (vec[mid] > n) right = mid - 1;
	}

	return false;
}

// �ִ� ������� ��ȯ
// ��Ŭ���� ȣ���� - ����Լ� ���
int Gcd(int a, int b)
{
	if (a % b == 0) return b;
	else return Gcd(b, a % b);
}
// �ִ� ������� ��ȯ
int Lcm(int a, int b)
{
	return (a * b) / Gcd(a, b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N; // ���� ����
	cin >> N;
	vector<int> rings; // ���� �������� ������ ����, ���� ������ 1 ~ 1000
	// �Է� �ޱ� 
	for (int i = 0; i < N; i++)
	{
		int radius;
		cin >> radius;
		rings.push_back(radius);
	}

	// 1. 1��°���� ����� ���Ѵ�.
	// 2. 1��° ���� �����ϰ� �ݺ��� ����
	// 3. 1��° ���� ����� �����ϴ��� Ȯ��
	// 3-1. true�� ��� �ּҰ������ �������� ������ ���� ���
	// 3-2. false�� ��� �ּҰ������ ���ϰ�, �ּҰ������ �������� ������ ���� ���
	vector<int> first = GetFactor(rings.front()); // 1��°���� ���
	for (int i = 1; i < rings.size(); i++)
	{
		if (IsExist(first, rings[i]) == true) cout << rings[0] / rings[i] << "/1" << '\n';
		else
		{
			int lcm = Lcm(rings[i], rings[0]);
			cout << lcm / rings[i] << "/" << lcm / rings[0] << '\n';
		}
	}
	return 0;
}