/*
����
���л� ��������� 90%�� �ڽ��� �ݿ��� ����� �Ѵ´ٰ� �����Ѵ�. ����� �׵鿡�� ���� ������ �˷���� �Ѵ�.

�Է�
ù° �ٿ��� �׽�Ʈ ���̽��� ���� C�� �־�����.

��° �ٺ��� �� �׽�Ʈ ���̽����� �л��� �� N(1 �� N �� 1000, N�� ����)�� ù ���� �־�����, �̾ N���� ������ �־�����. ������ 0���� ũ�ų� ����, 100���� �۰ų� ���� �����̴�.

���
�� ���̽����� �� �پ� ����� �Ѵ� �л����� ������ �ݿø��Ͽ� �Ҽ��� ��° �ڸ����� ����Ѵ�.
*/

#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int c; // �׽�Ʈ ���̽�
	cin >> c;

	for (int i = 0; i < c; i++)
	{
		int n; // �л��� �� 
		cin >> n;
		double* arr = new double[n]; // ������ ���� �迭 
		double total = 0; // ����
		// �� �Է� �� ���� ���
		for (int j = 0; j < n; j++)
		{
			cin >> arr[j];
			total += arr[j];
		}
		
		double aver = total / n; // ���
		
		int count = 0;
		for (int j = 0; j < n; j++)
		{
			if (arr[j] > aver)
			{
				count += 1;
			}
		}
		cout << fixed; // �Ҽ��� ����
		cout.precision(3);
		cout << ((double)count / (double)n) * 100 << "%" << '\n';
	}

	return 0;
}