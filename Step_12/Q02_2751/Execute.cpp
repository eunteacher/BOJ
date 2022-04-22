/*
����
N���� ���� �־����� ��, �̸� ������������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� ���� N(1 �� N �� 1,000,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ���� �־�����. �� ���� ������ 1,000,000���� �۰ų� ���� �����̴�. ���� �ߺ����� �ʴ´�.

���
ù° �ٺ��� N���� �ٿ� ������������ ������ ����� �� �ٿ� �ϳ��� ����Ѵ�.
*/
#include <iostream>
using namespace std;

void Swap(int & a, int & b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

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

void QuickSort(int arr[], int left, int right)
{
	if(left < right)
	{
		int index = Partition(arr, left, right);

		QuickSort(arr, left, index - 1);
		QuickSort(arr, index + 1, right);
	}
}

void Merge(int arr[], int start, int mid, int end)
{
	int left = start;
	int right = mid + 1;
	int destIndex = 0; // ������ �迭�� �ε���
	int* dest = new int[end - start + 1]; // ������ �迭

	while (left <= mid && right <= end) // �� ���� ���ؼ� �� ���� ���� ���� �迭�� �־��ش�.
	{
		if (arr[left] < arr[right])
			dest[destIndex++] = arr[left++];
		else
			dest[destIndex++] = arr[right++];
	}

	// �պ� �������� ������ �����ǰų�, �߰��� ������ dest �迭�� �־��ش�.
	while (left <= mid)
		dest[destIndex++] = arr[left++];
	while (right <= end)
		dest[destIndex++] = arr[right++];

	// �Է¹��� �迭 arr�� ���ĵ� dest �迭�� �����Ѵ�.
	destIndex = 0;
	for (int i = start; i <= end; i++)
		arr[i] = dest[destIndex++];

	delete[] dest;
}

void MergeSort(int arr[], int start, int end)
{
	// ������ �����Ͱ� ���� ���
	if (end - start < 1)
		return;

	int mid = (start + end) / 2; // �߰� ��

	// ����
	MergeSort(arr, start, mid);
	MergeSort(arr, mid + 1, end);

	// ����
	Merge(arr, start, mid, end);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// �ð� ���⵵�� O(nlogn)�� ���� �˰��� ����ϱ�.
	int N;
	cin >> N;
	int* arr = new int[N];

	for (int i = 0; i < N; i++)
		cin >> arr[i];
	// �o��Ʈ�� �ð� �ʰ��� ��� �� ������ ���ĵ� ��� ���ۺ��⵵�� O(n^2)�̶� 
	//QuickSort(arr, 0, N - 1);
	MergeSort(arr, 0, N - 1);
	for (int i = 0; i < N; i++)
		cout << arr[i] << '\n';

	delete[] arr;
	return 0;
}