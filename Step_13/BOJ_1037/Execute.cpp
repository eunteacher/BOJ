/*
문제
양수 A가 N의 진짜 약수가 되려면, N이 A의 배수이고, A가 1과 N이 아니어야 한다. 어떤 수 N의 진짜 약수가 모두 주어질 때, N을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N의 진짜 약수의 개수가 주어진다. 이 개수는 50보다 작거나 같은 자연수이다. 둘째 줄에는 N의 진짜 약수가 주어진다. 1,000,000보다 작거나 같고, 2보다 크거나 같은 자연수이고, 중복되지 않는다.

출력
첫째 줄에 N을 출력한다. N은 항상 32비트 부호있는 정수로 표현할 수 있다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N; // 약수의 개수 
	vector<int> factors; // 약수

	// 약수의 개수와 약수 입력
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int tmp = 0;
		cin >> tmp;
		factors.push_back(tmp);
	}

	// 최소 약수 * 최대 약수 = 자연수를 이용
	// 정렬 후 첫 번째 원소와 마지막 원소를 곱해서 출력
	sort(factors.begin(), factors.end()); // 정렬
	cout << factors.front() * factors.back();

	return 0;
}