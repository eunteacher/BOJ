/*
����
�迭�� �����ϴ� ���� ����. ���� �־�����, �� ���� �� �ڸ����� ������������ �����غ���.

�Է�
ù° �ٿ� �����Ϸ��� �ϴ� �� N�� �־�����. N�� 1,000,000,000���� �۰ų� ���� �ڿ����̴�.

���
ù° �ٿ� �ڸ����� ������������ ������ ���� ����Ѵ�.
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// �������� ����
bool Compare(const int & a, const int & b)
{
	return a > b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// �Է�
	string cnt;
	cin >> cnt;

	// ����
	sort(cnt.begin(), cnt.end(), Compare);
	cout << cnt;

	return 0;
}