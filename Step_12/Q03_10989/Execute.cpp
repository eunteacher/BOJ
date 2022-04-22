/*
����
N���� ���� �־����� ��, �̸� ������������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� ���� N(1 �� N �� 10,000,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ���� �־�����. �� ���� 10,000���� �۰ų� ���� �ڿ����̴�.

���
ù° �ٺ��� N���� �ٿ� ������������ ������ ����� �� �ٿ� �ϳ��� ����Ѵ�.
*/
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N; // �迭�� ũ��
	int count[10001] = { 0, };
	int max = 0; // �Է¹��� �� �� �ִ�

	// input
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int tmp = 0;
		cin >> tmp;
		count[tmp]++; // ī����
		// �Է� ���� �� �� �ִ� ���ϱ�
		if (tmp > max)
			max = tmp;
	}

	for (int i = 1; i < max + 1; i++)
	{
		// ���� �� ���� �� ���
		while (count[i]-- > 0)
			cout << i << '\n';
	}

	return 0;
}