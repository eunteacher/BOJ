/*
문제
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 수가 주어진다. 이 수는 절댓값이 1,000,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.

출력
첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.
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
	int start = left; // 중간값을 모르기 때문에 맨 앞을 기준으로 삼는다.
	int pivot = arr[start];

	left++; // left가 start이기 때문에 하나 증가된 값부터 시작

	while (left <= right) // right가 left보다 크면 계속 반복
	{
		// arr[left]가 pivot보다 작고, left가 right보다 작을 경우 left를 -> 방향으로 계속 움직인다.
		// 즉, arr[left]가 pivot보다 큰 값을 찾을 때까지 반복한다.
		while (arr[left] <= pivot && left < right)
			left++;

		// arr[right]가 pivot보다 크고, left가 right보다 작거나 같은 경우 right를 <- 방향으로 계속 움직인다.
		// 즉, arr[right]가 pivot보다 작은 값을 찾을 때까지 반복한다.
		while (arr[right] > pivot && left <= right)
			right--;

		if (left < right) // left는 큰 값을, right는 작은 값을 찾은 경우 
			Swap(arr[left], arr[right]);
		else // 서로 교차 혹은 만난 경우
			break;
	}

	// right 값을 피벗으로 사용한다.
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
	int destIndex = 0; // 분할한 배열의 인덱스
	int* dest = new int[end - start + 1]; // 분할한 배열

	while (left <= mid && right <= end) // 두 수를 비교해서 더 작은 값을 먼저 배열에 넣어준다.
	{
		if (arr[left] < arr[right])
			dest[destIndex++] = arr[left++];
		else
			dest[destIndex++] = arr[right++];
	}

	// 합병 과정에서 순서가 수정되거나, 추가된 값들을 dest 배열에 넣어준다.
	while (left <= mid)
		dest[destIndex++] = arr[left++];
	while (right <= end)
		dest[destIndex++] = arr[right++];

	// 입력받은 배열 arr에 정렬된 dest 배열을 복사한다.
	destIndex = 0;
	for (int i = start; i <= end; i++)
		arr[i] = dest[destIndex++];

	delete[] dest;
}

void MergeSort(int arr[], int start, int end)
{
	// 정렬할 데이터가 없을 경우
	if (end - start < 1)
		return;

	int mid = (start + end) / 2; // 중간 값

	// 분할
	MergeSort(arr, start, mid);
	MergeSort(arr, mid + 1, end);

	// 병합
	Merge(arr, start, mid, end);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 시간 복잡도가 O(nlogn)인 정렬 알고리즘 사용하기.
	int N;
	cin >> N;
	int* arr = new int[N];

	for (int i = 0; i < N; i++)
		cin >> arr[i];
	// 쿽소트는 시간 초과가 뜬다 그 이유는 정렬된 경우 시작복잡도가 O(n^2)이라서 
	//QuickSort(arr, 0, N - 1);
	MergeSort(arr, 0, N - 1);
	for (int i = 0; i < N; i++)
		cout << arr[i] << '\n';

	delete[] arr;
	return 0;
}