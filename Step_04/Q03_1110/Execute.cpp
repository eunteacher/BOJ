/*
����
0���� ũ�ų� ����, 99���� �۰ų� ���� ������ �־��� �� ������ ���� ������ �� �� �ִ�. ���� �־��� ���� 10���� �۴ٸ� �տ� 0�� �ٿ� �� �ڸ� ���� �����, �� �ڸ��� ���ڸ� ���Ѵ�. �� ����, �־��� ���� ���� ������ �ڸ� ���� �տ��� ���� ���� ���� ������ �ڸ� ���� �̾� ���̸� ���ο� ���� ���� �� �ִ�. ���� ���� ����.

26���� �����Ѵ�. 2+6 = 8�̴�. ���ο� ���� 68�̴�. 6+8 = 14�̴�. ���ο� ���� 84�̴�. 8+4 = 12�̴�. ���ο� ���� 42�̴�. 4+2 = 6�̴�. ���ο� ���� 26�̴�.

���� ���� 4������ ���� ���� ���ƿ� �� �ִ�. ���� 26�� ����Ŭ�� ���̴� 4�̴�.

N�� �־����� ��, N�� ����Ŭ�� ���̸� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� �־�����. N�� 0���� ũ�ų� ����, 99���� �۰ų� ���� �����̴�.

���
ù° �ٿ� N�� ����Ŭ ���̸� ����Ѵ�.
*/

#include <iostream>
using namespace std;

int GetRadixNum(int n, int radix)
{
	return (n / radix) % 10;
}

int NewNum(int arr[], int n)
{
	arr[0] = GetRadixNum(n, 10); // 10�� �ڸ� ����
	arr[1] = GetRadixNum(n, 1); // 1�� �ڸ� ���� 

	return arr[1] * 10 + GetRadixNum(arr[0] + arr[1], 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[2];

	int n; // �Է� ���� n
	int count = 1;
	int result = 0;
	
	cin >> n;
	
	if (n < 10)
	{
		arr[0] = 0;
		arr[1] = n;
	}
	
	result = NewNum(arr, n);
	while (true)
	{
		if (result == n)
		{
			break;
		}
		
		result = NewNum(arr, result);
		count++;
	}
	cout << count << '\n';

	return 0;
}