/*
문제
N!에서 뒤에서부터 처음 0이 아닌 숫자가 나올 때까지 0의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. (0 ≤ N ≤ 500)

출력
첫째 줄에 구한 0의 개수를 출력한다.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * 입력으로 숫자를 받고 그 숫자의 팩토리얼의 값을 string으로 전환해서 리턴
 */
string Factor(int num)
{
	string tmp = "1";
	for (unsigned long long i = 1; i <= num; i++)
		tmp = to_string(stoull(tmp) * i);

	return tmp;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	/*
	 * 처음 풀이
	 * N!의 크기가 너무 커지므로 사용 불가 
	 */
	//string tmp = Factor(N);
	//int idx = tmp.size() - 1; // 문자열의 인덱스
	//int count = 0; // 0의 개수
	///*
	// * 문자열 전체를 검사, 숫자니까 size -1부터 시작
	// * 0이 나오면 카운트를 증가
	// * 0이 아닐 경우 bFlag를 true로 초기화하고 반복문 종료
	// */
	//while (idx > -1)
	//{
	//	if (tmp[idx] == '0') count++;
	//	else break;

	//	idx--;
	//}
	//cout << count;

	/*
	 * 2번째 풀이
	 * 0이 나오려면 10이 필요하다. 그렇기 때문에 (2 * 5)를 찾으면 되고, 중요한 것 5를 세는 것.
	 * 1부터 N까지 5로 나눠서 나머지가 0이 나오는 갯수를 센다
	 */

	vector<int> dp; // 각 숫자에 해당하는 5의 개수를 저장할 벡터 
	dp.assign(501, 0); // 미리 501개 할당
	for (int i = 1; i < N + 1; i++)
	{
		int count = 0; // 5의 개수 
		int tmp = i; // i의 값은 인덱스로 사용해야 되기 때문에 따로 선언
		while(true)
		{
			if(tmp % 5 == 0)
			{
				count++;
				tmp /= 5;
			}
			else break; // 나머지가 0이 아니면 반복문 종료 
		}
		dp[i] = count;
	}

	// 5의 총 개수 구하기 
	int total = 0;
	for (int i = 1; i <= N; i++)
		total += dp[i];

	cout << total;
	return 0;
}