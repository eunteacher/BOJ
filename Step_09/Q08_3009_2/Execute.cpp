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

	// ���簢���� 2���� ���� x���� 2���� ���� y���� �����ϹǷ� 3���� �� �� ���� ���� �ϳ��� ���� 4��° ���̴�.
	Vertex v; // 4��° ��
	if (rect[0].x == rect[1].x)
		v.x = rect[2].x;
	else if(rect[0].x == rect[2].x)
		v.x = rect[1].x;
	else if (rect[1].x == rect[2].x)
		v.x = rect[0].x;

	if (rect[0].y == rect[1].y)
		v.y = rect[2].y;
	else if (rect[0].y == rect[2].y)
		v.y = rect[1].y;
	else if (rect[1].y == rect[2].y)
		v.y = rect[0].y;

	cout << v.x << " " << v.y;
	return 0;
}