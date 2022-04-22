#include <iostream>
using namespace std;

#define MaxNum 10

int main()
{
	int data[] = { 5,3,3,4,7,0,0 }; // ������ �迭
	int sumArr[MaxNum] = { 0, }; // ������ �迭 ���� �� �ʱⰪ ����
	int countArr[MaxNum] = { 0, }; // ���ĵ� �迭
	int sortArr[7];
	// ���� Ƚ��  
	for (int i = 0; i < 7; i++)
		countArr[data[i]]++;

	// ���� ��
	sumArr[0] = countArr[0];
	for (int i = 1; i < MaxNum; i++)
		sumArr[i] = countArr[i] + sumArr[i - 1];

	// ���� �迭 �� �ֱ�
	for (int i = 6; i >= 0; i--)
	{
		int val = data[i];
		sortArr[sumArr[val] - 1] = val;
		sumArr[val]--;
	}

	// ���
	for (int i = 0; i < 7; i++)
		cout << sortArr[i] << " ";

	return 0;
}