/*
����
�¶��� ������ ������ ������� ���̿� �̸��� ������ ������� �־�����. �̶�, ȸ������ ���̰� �����ϴ� ������, ���̰� ������ ���� ������ ����� �տ� ���� ������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �¶��� ���� ȸ���� �� N�� �־�����. (1 �� N �� 100,000)

��° �ٺ��� N���� �ٿ��� �� ȸ���� ���̿� �̸��� �������� ���еǾ� �־�����. ���̴� 1���� ũ�ų� ������, 200���� �۰ų� ���� �����̰�, �̸��� ���ĺ� ��ҹ��ڷ� �̷���� �ְ�, ���̰� 100���� �۰ų� ���� ���ڿ��̴�. �Է��� ������ ������ �־�����.

���
ù° �ٺ��� �� N���� �ٿ� ���� �¶��� ���� ȸ���� ���� ��, ���̰� ������ ������ ������ �� �ٿ� �� �� ���̿� �̸��� �������� ������ ����Ѵ�.
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Member
{
	int index;
	int age;
	string name;
};

bool Compare(const Member & m1, const Member & m2)
{
	if(m1.age < m2.age)
	{
		return true;
	}
	else
	{
		if (m1.age == m2.age)
			return m1.index < m2.index;

		return false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N; // ȸ���� �� 
	cin >> N;

	vector<Member> members;
	for (int i = 0; i < N; i++)
	{
		Member m;
		cin >> m.age >> m.name;
		m.index = i + 1; // ������ ����
		members.push_back(m);
	}

	sort(members.begin(), members.end(), Compare); // ����
	// ���
	for (Member m : members)
		cout << m.age << " " << m.name << '\n';

	return 0;
}