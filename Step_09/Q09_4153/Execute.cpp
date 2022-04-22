/*
����
���� ����Ʈ�ε��� �� ������ ���̰� 3, 4, 5�� �ﰢ���� ���� �ﰢ���ΰ��� �˾Ƴ´�. �־��� ������ ���̷� �ﰢ���� �������� �ƴ��� �����Ͻÿ�.

�Է�
�Է��� �������� �׽�Ʈ���̽��� �־����� �������ٿ��� 0 0 0�� �Էµȴ�. �� �׽�Ʈ���̽��� ��� 30,000���� ���� ���� ������ �־�����, �� �Է��� ���� ���̸� �ǹ��Ѵ�.

���
�� �Է¿� ���� ���� �ﰢ���� �´ٸ� "right", �ƴ϶�� "wrong"�� ����Ѵ�.
*/
#include <iostream>
using namespace std;

bool Pythagoras(int a,int b, int c)
{
	// a^2 + b^2 = c^2 �� ���
	// a^2 + c^2 = b^2 �� ���
	// b^2 + c^2 = a^2 �� ���
	if (a * a + b * b == c * c)
		return true;
	else if (a * a + c * c == b * b)
		return  true;
	else if (b * b + c * c == a * a)
		return true;

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while(true)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 0 && b == 0 && c == 0)
			return 0;

		if (Pythagoras(a, b, c) == true)
			cout << "right" << '\n';
		else
			cout << "wrong" << '\n';
	}
	
	return 0;
}