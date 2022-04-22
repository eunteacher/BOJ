#include <iostream>
#include <ctime>
#include "Timer.h"
using namespace std;

// �Է� ���� a,b�� ��ȯ
void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
// ����
int Partition(int arr[], int left, int right)
{
	int start = left; // �߰����� �𸣱� ������ �� ���� �������� ��´�.
	int pivot = arr[start];

	left++; // left�� start�̱� ������ �ϳ� ������ ������ ����

	while (left <= right) // right�� left���� ũ�� ��� �ݺ�
	{
		// arr[left]�� pivot���� �۰�, left�� right���� ���� ��� left�� -> �������� ��� �����δ�.
		// ��, arr[left]�� pivot���� ū ���� ã�� ������ �ݺ��Ѵ�.
		while (arr[left] <= pivot && left < right)
			left++;

		// arr[right]�� pivot���� ũ��, left�� right���� �۰ų� ���� ��� right�� <- �������� ��� �����δ�.
		// ��, arr[right]�� pivot���� ���� ���� ã�� ������ �ݺ��Ѵ�.
		while (arr[right] > pivot && left <= right)
			right--;

		if (left < right) // left�� ū ����, right�� ���� ���� ã�� ��� 
			Swap(arr[left], arr[right]);
		else // ���� ���� Ȥ�� ���� ���
			break;
	}

	// right ���� �ǹ����� ����Ѵ�.
	Swap(arr[start], arr[right]);

	return right;
}
// �o ����
void QuickSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int index = Partition(arr, left, right);

		QuickSort(arr, left, index - 1);
		QuickSort(arr, index + 1, right);
	}
}
// ���� �Լ�
void Merge(int arr[], int start, int mid, int end)
{
	int left = start;
	int right = mid + 1;

	// �Է¹��� �迭�� �ε����� ���Ѵ�.
	int destIndex = 0;
	// �Է� ���� �迭, �����Ҵ��� �ϴ� ������ ũ�⸦ �𸣱� ������, ��Ÿ�� �߿� ũ�⸦ �����ַ��� 
	int* dest = new int[(end - start + 1)];

	// ����
	// �� ���� ���ؼ� �� ���� ���� ���� �迭�� �����Ѵ�.
	while (left <= mid && right <= end)
	{
		if (arr[left] < arr[right])
		{
			dest[destIndex] = arr[left];
			left++;
		}
		else
		{
			dest[destIndex] = arr[right];
			right++;
		}

		destIndex++;
	}

	// �պ� �������� ������ �����ǰų� �߰��� ������ dest �迭�� �����Ѵ�.
	while (left <= mid)
	{
		dest[destIndex++] = arr[left++];
	}

	while (right <= end)
	{
		dest[destIndex++] = arr[right++];
	}

	// �Է¹��� �迭 arr�� ���ĵ� dest �迭�� �����Ѵ�.
	destIndex = 0;
	for (int i = start; i <= end; i++)
	{
		arr[i] = dest[destIndex++];
	}

	delete[] dest;

}
// ���� �Լ�
void MergeSort(int arr[], int start, int end)
{
	// ������ �����Ͱ� ���ٸ�
	if (end - start < 1)
	{
		return;
	}

	// �߰���
	int mid = (start + end) / 2;

	// ����Լ��� ���� 
	MergeSort(arr, start, mid);
	MergeSort(arr, mid + 1, end);

	// ����
	Merge(arr, start, mid, end);
}
// �迭 ��� �Լ� 
void Print(int arr[], int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << " ";
	}
	cout << '\n';
}

int main()
{
	srand((unsigned int)time(NULL));
	const int arrSize = 10;
	int arr[arrSize];
	int arr2[arrSize];

	Timer t;

	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = rand() % 100; // 0 ~ 100 ���� ����
		arr2[i] = rand() % 100;
	}
	cout << "Before QuickSort" << '\n';
	Print(arr, arrSize);

	cout << "After QuickSort" << '\n';
	t.Start();
	QuickSort(arr, 0, arrSize - 1);
	Print(arr, arrSize);
	t.End();
	cout << "Quick Time : " << t.RunningTime() << '\n';
	cout << "--------------------------------------" << '\n';
	cout << "Before MergeSort" << '\n';
	Print(arr2, arrSize);
	cout << "After MergeSort" << '\n';
	t.Start();
	MergeSort(arr2, 0, arrSize - 1);
	Print(arr2, arrSize);
	t.End();
	cout << "MergeSort Time : " << t.RunningTime() << '\n';

	return 0;
}