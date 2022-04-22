/*
����
���������� for�� ������ Ǯ�� ���� �����ؾ� �� ���� �ִ�. ����� ����� ������ ���� ���� �Է¹ްų� ����� �� �ð��ʰ��� �� �� �ִٴ� ���̴�.

C++�� ����ϰ� �ְ� cin/cout�� ����ϰ��� �Ѵٸ�, cin.tie(NULL)�� sync_with_stdio(false)�� �� �� ������ �ְ�, endl ��� ���๮��(\n)�� ����. ��, �̷��� �ϸ� �� �̻� scanf/printf/puts/getchar/putchar �� C�� ����� ����� ����ϸ� �� �ȴ�.

Java�� ����ϰ� �ִٸ�, Scanner�� System.out.println ��� BufferedReader�� BufferedWriter�� ����� �� �ִ�. BufferedWriter.flush�� �� �������� �� ���� �ϸ� �ȴ�.

Python�� ����ϰ� �ִٸ�, input ��� sys.stdin.readline�� ����� �� �ִ�. ��, �̶��� �� ���� ���๮�ڱ��� ���� �Է¹ޱ� ������ ���ڿ��� �����ϰ� ���� ��� .rstrip()�� �߰��� �� �ִ� ���� ����.

���� �Է°� ��� ��Ʈ���� �����̹Ƿ�, �׽�Ʈ���̽��� ���� �Է¹޾Ƽ� ������ �� ���� ����� �ʿ�� ����. �׽�Ʈ���̽��� �ϳ� ���� �� �ϳ� ����ص� �ȴ�.

�ڼ��� ���� �� �ٸ� ����� ���� �� �ۿ� �����Ǿ� �ִ�.

�� ���α� �ۿ��� BOJ�� ��Ÿ ���� ���� ���� �� �� �ִ�.

�Է�
ù �ٿ� �׽�Ʈ���̽��� ���� T�� �־�����. T�� �ִ� 1,000,000�̴�. ���� T�ٿ��� ���� �� ���� A�� B�� �־�����. A�� B�� 1 �̻�, 1,000 �����̴�.

���
�� �׽�Ʈ���̽����� A+B�� �� �ٿ� �ϳ��� ������� ����Ѵ�.
*/

#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); // ios::sync_with_stdio()�� C�� stdio�� cpp�� iostream�� ����ȭ�����ִ� ������ �Ѵ�. �� �� iostream�� stdio�� ���۸� ��� ����ϱ� ������ �����̰� �߻��Ѵ�.
								// ios::sync_with_stdio(false)�� ���ָ� ����ȭ�� ��Ȱ��ȭ���� �ش�.
								// C++���� �������� ���۰� �����Ǿ� ����ϴ� ������ ���� �پ���.
	cin.tie(NULL); // cin�� cout�� ������ Ǯ���ش�. �⺻������ cin�� cout�� �����ְ� �����ִ� ��Ʈ������ �� ��Ʈ���� �ٸ� ��Ʈ������ �� InputOuput �۾��� �����ϱ� ���� 
				// �ڵ����� ���۸� ������� �����Ѵ�.

	int n;
	cin >> n;

	int a, b;
	for (int i = 1; i < n + 1; i++)
	{
		cin >> a >> b;
		cout << a + b << '\n';
	}

	return 0;
}