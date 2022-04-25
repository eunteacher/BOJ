/*
����
2���� ��� ���� �� N���� �־�����. ��ǥ�� x��ǥ�� �����ϴ� ������, x��ǥ�� ������ y��ǥ�� �����ϴ� ������ ������ ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� ���� N (1 �� N �� 100,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� i������ ��ġ xi�� yi�� �־�����. (-100,000 �� xi, yi �� 100,000) ��ǥ�� �׻� �����̰�, ��ġ�� ���� �� ���� ����.

���
ù° �ٺ��� N���� �ٿ� ���� ������ ����� ����Ѵ�.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Dot
{
	int x, y;
};

bool Compare(const Dot & d1, const Dot & d2)
{
	if (d1.x < d2.x) // x ��ǥ ���� �������� ����
	{
		return true;
	}
	else
	{
		if (d1.x == d2.x) // x���� ���ٸ�
			return d1.y < d2.y; // y��ǥ ���� �������� ����
		else
			return false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// �Է�
	int N; // ���� ����
	cin >> N;

	vector<Dot> dots;
	for (int i = 0; i < N; i++)
	{
		// �� ��ġ �Է�
		Dot dot;
		cin >> dot.x >> dot.y;
		dots.push_back(dot);
	}
	// ����
	sort(dots.begin(), dots.end(), Compare);
	// ���
	for (int i = 0; i < N; i++)
		cout << dots[i].x << " " << dots[i].y << '\n';

	return 0;
}