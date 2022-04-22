/*
����
�Ǻ���ġ ���� 0�� 1�� �����Ѵ�. 0��° �Ǻ���ġ ���� 0�̰�, 1��° �Ǻ���ġ ���� 1�̴�. �� ���� 2��° ���ʹ� �ٷ� �� �� �Ǻ���ġ ���� ���� �ȴ�.

�̸� ������ �Ẹ�� Fn = Fn-1 + Fn-2 (n �� 2)�� �ȴ�.

n=17�϶� ���� �Ǻ���ġ ���� �Ẹ�� ������ ����.

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597

n�� �־����� ��, n��° �Ǻ���ġ ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� n�� �־�����. n�� 20���� �۰ų� ���� �ڿ��� �Ǵ� 0�̴�.

���
ù° �ٿ� n��° �Ǻ���ġ ���� ����Ѵ�.
*/
#include <iostream>
using namespace std;

int Fibonacci(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return  1;
	else
		return Fibonacci(n - 1) + Fibonacci(n - 2);
		
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	cout << Fibonacci(n);

	return 0;
}