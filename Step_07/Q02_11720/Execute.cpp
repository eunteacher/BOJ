/*
����
N���� ���ڰ� ���� ���� �����ִ�. �� ���ڸ� ��� ���ؼ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ���� N (1 �� N �� 100)�� �־�����. ��° �ٿ� ���� N���� ������� �־�����.

���
�Է����� �־��� ���� N���� ���� ����Ѵ�.
*/
#include <iostream>
using namespace std;

int main()
{
	int n; // �Է� Ƚ��
	//char s[101];

	cin >> n;
	//cin >> s;

	char* s2 = new char[n + 1];
	cin >> s2;
	int i = 0;
	int total = 0; // �� ��
	while (i < n)
	{
		// s[i] char��
		//total += int(s[i] - '0');
		total += int(s2[i] - '0'); 
		i++;
	}
	cout << total;

	delete[] s2;
	return 0;
}