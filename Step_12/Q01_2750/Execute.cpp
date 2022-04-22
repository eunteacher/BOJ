/*
����
N���� ���� �־����� ��, �̸� ������������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� ���� N(1 �� N �� 1,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� �� �־�����. �� ���� ������ 1,000���� �۰ų� ���� �����̴�. ���� �ߺ����� �ʴ´�.

���
ù° �ٺ��� N���� �ٿ� ������������ ������ ����� �� �ٿ� �ϳ��� ����Ѵ�.
*/
#include <iostream>
using namespace std;

// �� ���� ��ȯ�ϴ� �Լ� 
void Swap(int & a, int & b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

// ���� ���� : ���� ������ �� ���Ҹ� �˻��Ͽ� �����ϴ� �˰���
void BubbleSort(int arr[], int size)
{
	for (int i = size - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(arr[j], arr[j + 1]);
			} // if (arr[j] > arr[j + 1])
		} // for j
	} // for size -1
}
// ���� ���� : �ش� ���Ҹ� ���� �ڸ��� �̹� ������ �ְ� � ���Ҹ� ������ �����ϴ� �˰���
void SelectSort(int arr[], int size)
{
	// ������ �ε����� �ڵ����� ���ĵǾ� �ֱ� ������ �������� �ʴ´�.
	for (int i = 0; i < size - 1; i++)
	{
		int min = i; // �ּڰ��� �ε���
		for (int j = i + 1; j < size; j++)
		{
			// ���� ���� ���� �ε����� min�� �ִ´�.
			if (arr[min] > arr[j])
				min = j;
		}

		// �ڸ� ��ȯ
		if (i != min)
			Swap(arr[i], arr[min]);
	}
}
// ���� ���� : �տ������� ���ʴ�� �����ϰ�, �̹� ���ĵ� �迭 �κа� ���Ͽ� �����ϴ� �˰���
void InsertSort(int arr[], int size)
{
	for (int i = 1; i < size; i++)
	{
		int key = arr[i];
		for (int j = i - 1; j >= 0; j--) // ����
		{
			// ������ �̵�
			if(key < arr[j])
			{
				arr[j + 1] = arr[j];
				arr[j] = key;
			} // if(key < arr[j])
		} // for j - 1
	} // for i
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// �ð� ���⵵�� O(n^2)�� ���� �˰��� ����ϱ�.
	int N;
	cin >> N;
	int arr[1001];
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	//BubbleSort(arr, N);
	//SelectSort(arr, N);
	InsertSort(arr, N);
	for (int i = 0; i < N; i++)
		cout << arr[i] << '\n';

	return 0;
}