/*
����
�־��� �� N�� �߿��� �Ҽ��� �� ������ ã�Ƽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù �ٿ� ���� ���� N�� �־�����. N�� 100�����̴�. �������� N���� ���� �־����µ� ���� 1,000 ������ �ڿ����̴�.

���
�־��� ���� �� �Ҽ��� ������ ����Ѵ�.
*/
#include <iostream>
using namespace std;

bool FindPrimeNum(int num)
{
	// 1�� �Ҽ��� �ƴϴ�.
	if (num == 1)
		return false;
	
	// n�� ������ ������ � ���ε� ����������� �ʴ´ٸ� �Ҽ���.
	// num�� ��Ʈ�Լ��� ������� �ʰ�, i�� ������ ����Ѵ�.
	for (int i = 2; i * i <= num; i++)
	{
		// ������ �������� �Ҽ��� �ƴϴ�.
		if (num % i == 0)
			return false;
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;

	int arr[101] = { 0, };
	int primeNum = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (FindPrimeNum(arr[i]) == true)
			primeNum++;
	}

	cout << primeNum;

	return 0;
}