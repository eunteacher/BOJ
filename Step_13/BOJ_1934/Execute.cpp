/*
����
�� �ڿ��� A�� B�� ���ؼ�, A�� ����̸鼭 B�� ����� �ڿ����� A�� B�� �������� �Ѵ�. �̷� ����� �߿��� ���� ���� ���� �ּҰ������� �Ѵ�. ���� ���, 6�� 15�� ������� 30, 60, 90���� ������, �ּ� ������� 30�̴�.

�� �ڿ��� A�� B�� �־����� ��, A�� B�� �ּҰ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� T(1 �� T �� 1,000)�� �־�����. ��° �ٺ��� T���� �ٿ� ���ļ� A�� B�� �־�����. (1 �� A, B �� 45,000)

���
ù° �ٺ��� T���� �ٿ� A�� B�� �ּҰ������ �Է¹��� ������� �� �ٿ� �ϳ��� ����Ѵ�.
*/
#include <iostream>
using namespace std;

// �ִ� ������� ���ϴ� �Լ�
// ��Ŭ���� ȣ���� ���
// f(a,b) = gcd(a,b)�� �Ҷ�, a mod b = 0 �̶�� f(a,b) = b�̰�, a mod b = 0 �� �ƴ϶�� f(a,b) = f(b, a mod b)�� ����
// ��� �Լ� �̿�
int GCD(int a, int b)
{
	int mod = a % b;

	if (a % b == 0)	return b;
	else return GCD(b, a % b);
}
// �ּ� ����� ���ϱ�
// a * b = GCD(a,b) * LCM(a,b)
int LCM(int a, int b)
{
	return (a * b) / GCD(a, b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	int a, b;
	for(int i=0; i<N;i++)
	{
		cin >> a >> b;
		cout << LCM(a, b) << '\n';
	}

	return 0;
}