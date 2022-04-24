/*
���� ó���ϴ� ���� ����п��� ����� �߿��� ���̴�. ����п��� N���� ���� ��ǥ�ϴ� �⺻ ��谪���� ������ ���� �͵��� �ִ�. ��, N�� Ȧ����� ��������.

������ : N���� ������ ���� N���� ���� ��
�߾Ӱ� : N���� ������ �����ϴ� ������ �������� ��� �� �߾ӿ� ��ġ�ϴ� ��
�ֺ� : N���� ���� �� ���� ���� ��Ÿ���� ��
���� : N���� ���� �� �ִ񰪰� �ּڰ��� ����
N���� ���� �־����� ��, �� ���� �⺻ ��谪�� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� ���� N(1 �� N �� 500,000)�� �־�����. ��, N�� Ȧ���̴�. �� ���� N���� �ٿ��� �������� �־�����. �ԷµǴ� ������ ������ 4,000�� ���� �ʴ´�.

���
ù° �ٿ��� �������� ����Ѵ�. �Ҽ��� ���� ù° �ڸ����� �ݿø��� ���� ����Ѵ�.

��° �ٿ��� �߾Ӱ��� ����Ѵ�.

��° �ٿ��� �ֺ��� ����Ѵ�. ���� �� ���� ������ �ֺ� �� �� ��°�� ���� ���� ����Ѵ�.

��° �ٿ��� ������ ����Ѵ�.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// �ֺ� ���ϱ�
int MaxCounting(int count[])
{
	int max = 0; // �ֺ�
	
	for (int i = 0; i < 8001; i++)
	{
		// �ֺ� ã�� 
		if (max < count[i])
			max = count[i];
	}

	// ���� �ֺ��� ���� ���� ã��
	vector<int> tmp;
	int idx = 0;
	for (int i = 0; i < 8001; i++)
	{
		if (count[i] == max)
		{
			tmp.push_back(i - 4000);
			idx++;
			if(idx > 1)
				break;
		}
	}

	if (tmp.size() > 1)
		return tmp[1];
	else
		return tmp[0];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// �Ҽ��� ù° �ڸ����� �ݿø�
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(1);

	// ���� ���� �Է�
	int N;
	cin >> N;

	// N���� ����
	vector<int> ans;
	int count[8001] = { 0, }; // 
	int total = 0;
	for (int i = 0; i < N; i++)
	{
		int tmp = 0;
		cin >> tmp;
		total += tmp;
		count[tmp + 4000]++; // ī����
		ans.push_back(tmp);
	}

	// ��� ���
	float aver = (float)total / (float)N;
	cout << (int)roundf(aver) << '\n';
	// �߾Ӱ� ���ϱ�
	sort(ans.begin(), ans.end());
	int center = ans[N / 2];
	cout << center << '\n';
	// �ֺ� ���ϱ�
	int maxCountVal = MaxCounting(count);
	cout << maxCountVal << '\n';
	// ���� ���ϱ�
	// ���ĵǾ� �ֱ� ������ ������ �ε����� ù ��° �ε����� ���ϸ� �ȴ�.
	int range = ans[N - 1] - ans[0];
	cout << range;

	return 0;
}