/*
����
�� ���� A�� B�� �Է¹��� ����, A+B�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
�Է��� ���� ���� �׽�Ʈ ���̽��� �̷���� �ִ�.

�� �׽�Ʈ ���̽��� �� �ٷ� �̷���� ������, �� �ٿ� A�� B�� �־�����. (0 < A, B < 10)

���
�� �׽�Ʈ ���̽����� A+B�� ����Ѵ�.
*/

#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	while (true)
	{
		cin >> a >> b;
		// EOF(End Of File) ������ ��, �� �̻� ���� �����Ͱ� ����.
		// cin���� �Է��� �������� �� ��, EOF��� �Է��� ��ҵǰ� cin.eof()�� true�� ��ȯ�Ѵ�. �̸� �̿��Ͽ� ������ ����� ������ �Է��� �޴� �ڵ带 �ۼ��� �� �ִ�.
		if (cin.eof() == true)
		{
			break;
		}
		cout << a + b << '\n';
	}

	return 0;
}




