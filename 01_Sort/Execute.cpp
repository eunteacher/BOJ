#include <iostream>
#include "Timer.h"
using namespace std;

// �� ���� ��ȯ�ϴ� �Լ�
void Swap(int & a, int & b)
{
	int temp = a;
	a = b;
	b = temp;
}
// ���� ����
void BubbleSort(int arr[], int size)
{
	for (int i = size - 1; i > 0; i--)
	{
		// size��ŭ �ݺ�
		for (int j = 0; j < i; j++)
		{
			// �� �� ��ȯ
			if (arr[j] > arr[j + 1])
			{
				Swap(arr[j], arr[j + 1]);
			}
		}
	}
}

// ���� ����
void SelectionSort(int arr[], int size)
{
	// ������ �ε����� �ڵ����� ���ĵǾ� �ֱ� ������ �������� �ʴ´�.
	for (int i = 0; i < size - 1; i++)
	{
		int min = i; // �ּڰ�
		for (int j = i + 1; j < size; j++)
		{
			// ���� ���� ���� i�� ������.
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}

		// ��ȯ
		if (i != min) // �ּڰ��� ��ġ�� i�� ���ٸ� ��ȯ�����ʴ´�.
		{
			Swap(arr[i], arr[min]);
		}
	} // for i
}

// ���� ����
void InsertionSort(int arr[], int size)
{
	for (int i = 1; i < size; i++)
	{
		int key = arr[i]; // ó���� 2��°�� Key�� �ȴ�.
		for (int j = i - 1; j >= 0; j--)
		{
			// �������� ����
			if (key < arr[j])
			{
				// ������ �̵�
				arr[j + 1] = arr[j];
				arr[j] = key;
			}
		}
	}
}

// �迭 ��� �Լ�
void Print(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << '\n';
}

int main()
{
	// �ð� ���⵵�� O(log(n^2)�� ����
	Timer t;
	int arr[5] = { 7,4,5,1,3 };
	int arr2[5] = { 8,3,2,7,9 };
	int arr3[5] = { 1,9,5,3,6 };
	
	cout << "Before Bubble Sort " << '\n';
	Print(arr, 5);

	cout << "After Bubble Sort " << '\n';
	t.Start();
	BubbleSort(arr, 5);
	t.End();
	Print(arr, 5);
	cout<<"Bubble Sort Time : " << t.RunningTime() << '\n';
	cout << "-------------------------------------" << '\n';
	
	cout << "Before Selection Sort " << '\n';
	Print(arr2, 5);
	cout << "After Selection Sort " << '\n';
	t.Start();
	SelectionSort(arr2, 5);
	t.End();
	Print(arr2, 5);
	cout << "Selection Sort Time : " << t.RunningTime() << '\n';
	cout << "-------------------------------------" << '\n';

	cout << "Before Insertion Sort " << '\n';
	Print(arr3, 5);

	cout << "After Insertion Sort " << '\n';
	t.Start();
	InsertionSort(arr3, 5);
	t.End();
	Print(arr3, 5);
	cout << "Insertion Sort Time : " << t.RunningTime() << '\n';

	return 0;
}