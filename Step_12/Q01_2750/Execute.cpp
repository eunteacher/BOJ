/*
문제
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000)이 주어진다. 둘째 줄부터 N개의 줄에는 수 주어진다. 이 수는 절댓값이 1,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.

출력
첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.
*/
#include <iostream>
using namespace std;

// 두 수를 교환하는 함수 
void Swap(int & a, int & b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

// 버블 정렬 : 서로 인접한 두 원소를 검사하여 정렬하는 알고리즘
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
// 선택 정렬 : 해당 원소를 넣을 자리는 이미 정해져 있고 어떤 원소를 넣을지 선택하는 알고리즘
void SelectSort(int arr[], int size)
{
	// 마지막 인덱스는 자동으로 정렬되어 있기 때문에 정렬하지 않는다.
	for (int i = 0; i < size - 1; i++)
	{
		int min = i; // 최솟값의 인덱스
		for (int j = i + 1; j < size; j++)
		{
			// 제일 작은 값의 인덱스를 min에 넣는다.
			if (arr[min] > arr[j])
				min = j;
		}

		// 자리 교환
		if (i != min)
			Swap(arr[i], arr[min]);
	}
}
// 삽입 정렬 : 앞에서부터 차례대로 정렬하고, 이미 정렬된 배열 부분과 비교하여 삽입하는 알고리즘
void InsertSort(int arr[], int size)
{
	for (int i = 1; i < size; i++)
	{
		int key = arr[i];
		for (int j = i - 1; j >= 0; j--) // 역순
		{
			// 데이터 이동
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

	// 시간 복잡도가 O(n^2)인 정렬 알고리즘 사용하기.
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