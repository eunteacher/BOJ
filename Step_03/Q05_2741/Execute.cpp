/*
 ����
 �ڿ��� N�� �־����� ��, 1���� N���� �� �ٿ� �ϳ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
 
 �Է�
 ù° �ٿ� 100,000���� �۰ų� ���� �ڿ��� N�� �־�����.
 
 ���
 ù° �ٺ��� N��° �� ���� ���ʴ�� ����Ѵ�.
*/
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int index = 1;
	do
	{
		cout << index++ << '\n';
		
	} while (index < n + 1);


	return 0;
}