/*
 * ���� ���� ���� �� �ϳ��� �־��� ���� ��� ��и鿡 ���ϴ��� �˾Ƴ��� ���̴�. ��и��� �Ʒ� �׸�ó�� 1~4���� ��ȣ�� ���´�.
 * "Quadrant n"�� "�� n��и�"�̶�� ���̴�. ���� ��� ��ǥ�� (12, 5)�� �� A�� x��ǥ�� y��ǥ�� ��� ����̹Ƿ� �� 1��и鿡 ���Ѵ�. �� B�� x��ǥ�� �����̰� y��ǥ�� ����̹Ƿ�
 * �� 2��и鿡 ���Ѵ�. ���� ��ǥ�� �Է¹޾� �� ���� ��� ��и鿡 ���ϴ��� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�.
 */

#include <iostream>
using namespace std;

int WhatQuad(int x, int y)
{
	if (x > 0 && y > 0)
	{
		return 1;
	}
	else if (x < 0 && y > 0)
	{
		return 2;
	}
	else if (x < 0 && y < 0)
	{
		return 3;
	}
	else if (x > 0 && y < 0)
	{
		return 4;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int x, y;
	cin >> x >> y;

	cout << WhatQuad(x, y);

	return 0;
}