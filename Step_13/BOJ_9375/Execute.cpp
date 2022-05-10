/*
����
�غ��̴� �мǿ� �ſ� �ΰ��ؼ� �ѹ� �Ծ��� �ʵ��� ������ ���� �ٽ� ���� �ʴ´�. ���� ��� ���� �غ��̰� �Ȱ�, ��Ʈ, ����, �Ź��� �Ծ��ٸ�, �������� ������ �߰��� �԰ų� �Ȱ��� ��� �����ϰų� �ؾ��Ѵ�. �غ��̰� ���� �ǻ���� �־������� ���� �غ��̴� �˸��� �ƴ� ���·� ��ĥ���� �ۿ� ���ƴٴ� �� ������?

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� �־�����. �׽�Ʈ ���̽��� �ִ� 100�̴�.

�� �׽�Ʈ ���̽��� ù° �ٿ��� �غ��̰� ���� �ǻ��� �� n(0 �� n �� 30)�� �־�����.
���� n������ �غ��̰� ���� �ǻ��� �̸��� �ǻ��� ������ �������� ���еǾ� �־�����. ���� ������ �ǻ��� �ϳ��� ���� �� �ִ�.
��� ���ڿ��� 1�̻� 20������ ���ĺ� �ҹ��ڷ� �̷���������� ���� �̸��� ���� �ǻ��� �������� �ʴ´�.

���
�� �׽�Ʈ ���̽��� ���� �غ��̰� �˸��� �ƴ� ���·� �ǻ��� ���� �� �ִ� ��츦 ����Ͻÿ�.
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// ���� �̸��� ���� �ǻ��� �������� �����Ƿ� ������ �߿�
	// ���� ��� ���ڰ� 2������� ���� �� �ִ� ����� ���� 2 + 1 (1�� �ƹ��͵� �������� ���� ���)
	// �������ڸ�, (A������ a��, B������ b��, C������ c��)�� �ִٰ� �����ϸ�
	// (a+1)*(b+1)*(c+1) �̶� ���� ����
	// �� �Ŀ��� �ƹ��͵� ���� ���� ��츦 �����ϸ� �ȴ�.
	// ��, (a+1)*(b+1)*(c+1)-1

	int T;
	cin >> T; // �ִ� 100
	for (int i = 0; i < T; i++)
	{
		int n;
		cin >> n; // 0 <= n <= 30
		map<string, int> m; // ������ ������ �ش��ϴ� ����
		for (int j = 0; j < n; j++)
		{
			string value, key;
			cin >> value >> key;
			m[key]++; // ������ ������ ���� 
		}

		int count = 1;
		for (auto iter = m.begin(); iter != m.end(); ++iter)
			count *= iter->second + 1;

		cout << count - 1 << '\n';
	}

	return 0;
}