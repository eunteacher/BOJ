/*
����
�� ���� �־����� ��, �࿡ ������ ���簢���� ����� ���ؼ� �ʿ��� �� ��° ���� ã�� ���α׷��� �ۼ��Ͻÿ�.

�Է�
�� ���� ��ǥ�� �� �ٿ� �ϳ��� �־�����. ��ǥ�� 1���� ũ�ų� ����, 1000���� �۰ų� ���� �����̴�.

���
���簢���� �� ��° ���� ��ǥ�� ����Ѵ�.
*/
#include <iostream>
using namespace std;

// ���� 
struct Vertex
{
	int x;
	int y;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// �� �� 
	Vertex rect[3];
	// �� ���� �� �Է�
	for (int i = 0; i < 3; i++)
	{
		cin >> rect[i].x >> rect[i].y;
	}

	// ���簢���� 2���� ���� x���� 2���� ���� y���� ����
	int equalX = 0; // ���� x��
	int equalY = 0; // ���� y��
	// ���� ���� ���� x,y ���� �̴� ����
	for (int i = 0; i < 3; i++)
	{
		for (int j = i + 1; j < 3; j++)
		{
			if(rect[i].x == rect[j].x)
			{
				equalX = rect[i].x;
			}

			if (rect[i].y == rect[j].y)
			{
				equalY = rect[i].y;
			}
		}
	}

	Vertex v; // �ʿ��� 4��° ��
	// ���� ���� x���� ���� ���� y���� �̴� ����
	for (int i = 0; i < 3; i++)
	{
		if(equalX != rect[i].x)
		{
			v.x = rect[i].x;
		}

		if (equalY != rect[i].y)
		{
			v.y = rect[i].y;
		}
	}

	cout << v.x << " " << v.y;
	return 0;
}