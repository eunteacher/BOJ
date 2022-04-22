/*
����
N���� ������ �־�����. �̶�, �ּڰ��� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ���� N (1 �� N �� 1,000,000)�� �־�����. ��° �ٿ��� N���� ������ �������� �����ؼ� �־�����. ��� ������ -1,000,000���� ũ�ų� ����, 1,000,000���� �۰ų� ���� �����̴�.

���
ù° �ٿ� �־��� ���� N���� �ּڰ��� �ִ��� �������� ������ ����Ѵ�.
*/

#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int input;
	cin >> input;

	int* arr = new int[input];

	for (int i = 0; i < input; i++)
	{
		cin >> arr[i];
	}

	int max = arr[0]; // �ִ�
	int min = arr[0]; // �ּڰ�
	for (int i = 1; i < input; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}

		if (min > arr[i])
		{
			min = arr[i];
		}
	}

	cout << min << " " << max << '\n';

	return 0;
}