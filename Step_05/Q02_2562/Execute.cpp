/*
����
9���� ���� �ٸ� �ڿ����� �־��� ��, �̵� �� �ִ��� ã�� �� �ִ��� �� ��° �������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

���� ���, ���� �ٸ� 9���� �ڿ���

3, 29, 38, 12, 57, 74, 40, 85, 61

�� �־�����, �̵� �� �ִ��� 85�̰�, �� ���� 8��° ���̴�.

�Է�
ù° �ٺ��� ��ȩ ��° �ٱ��� �� �ٿ� �ϳ��� �ڿ����� �־�����. �־����� �ڿ����� 100 ���� �۴�.

���
ù° �ٿ� �ִ��� ����ϰ�, ��° �ٿ� �ִ��� �� ��° �������� ����Ѵ�.
*/

#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	const int arrSize = 9;
	int arr[arrSize];

	for (int i = 0; i < arrSize; i++)
	{
		cin >> arr[i];
	}

	int max = arr[0];
	int count = 1;
	for (int i = 1; i < arrSize; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
			count = i + 1;
		}
	}
	cout << max << '\n';
	cout << count << '\n';
	return 0;
}