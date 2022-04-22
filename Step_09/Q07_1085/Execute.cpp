/*
����
�Ѽ��� ���� (x, y)�� �ִ�. ���簢���� �� ���� ��ǥ�࿡ �����ϰ�, ���� �Ʒ� �������� (0, 0), ������ �� �������� (w, h)�� �ִ�. ���簢���� ��輱���� ���� �Ÿ��� �ּڰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� x, y, w, h�� �־�����.

���
ù° �ٿ� ������ ������ ����Ѵ�.

����
1 �� w, h �� 1,000
1 �� x �� w-1
1 �� y �� h-1
x, y, w, h�� ����
*/
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x, y, w, h;

	cin >> x >> y >> w >> h;

	// h���� Ȥ�� w����� x�� ���� Ȥ�� y�� ���� �̷��� 4���� ����� �ִ�.
	// 4���� ��� �� ���� ª�� ����, �� �ּڰ��� ����ϸ� �ȴ�.

	// 4���� ����� �迭�� ��´�.
	int sides[4];
	sides[0] = w - x;
	sides[1] = h - y;
	sides[2] = x;
	sides[3] = y;

	// �ּڰ� ���ϱ�
	int min = sides[0];
	for (int i = 0; i < 4; i++)
	{
		if (min > sides[i])
			min = sides[i];
	}

	cout << min;
	
	return 0;
}