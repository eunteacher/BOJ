/*
문제
 
$n \choose m$의 끝자리 $0$의 개수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 정수 $n$, $m$ ($0 \le m \le n \le 2,000,000,000$, $n \ne 0$)이 들어온다.

출력
첫째 줄에
$n \choose m$의 끝자리 $0$의 개수를 출력한다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 * 1. 소인수분해 
 */
vector<int> PrimeFactor(int num)
{
	vector<int> res; // 값을 저장할 벡터 
	int tmp = 2;
	while (num != 1) // num ==  1이면 반복문 종료 
	{
		if (num % tmp == 0)
		{
			// 나누어 떨어질 경우  
			num /= tmp;
			res.push_back(tmp); 
			tmp = 2;
		}
		else tmp++; // 나누어 떨어지지 않을 경우 tmp++ 
	}
	return res;
}

/*
 * 소인수분해 - 응용
 * 특정 숫자 개수 뽑아내기 
 */
int PrimeFactorCount(int num, int n)
{
	int tmp = num; // num을 나눌 수 없기 때문에 임시 변수 선언 
	int count = 0; // 개수
	while (tmp > 0) // tmp가 0이 될 때까지 반복
	{
		tmp /= n;
		count += tmp; // tmp를 n으로 나눈 몫을 카운팅에 더한다.
	}

	return tmp;
}

/*
 * 입력으로 숫자를 받는다.
 * num을 소인수분해하여 2와 5의 개수를 카운팅한다.
 */
pair<unsigned long long, unsigned long long> Counting(unsigned long long num)
{
	pair<unsigned long long, unsigned long long> p;
	unsigned long long val1 = num;
	unsigned long long val2 = num;
	unsigned long long count = 0;

	// 팩토리얼 2 카운팅 
	while (val1 > 0)
	{
		val1 /= 2;
		count += val1;
	}
	p.first = count;
	count = 0;
	// 팩토리얼 5 카운팅 
	while (val2 > 0)
	{
		val2 /= 5;
		count += val2;
	}
	p.second = count;

	return p;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	unsigned long long n, m;
	cin >> n >> m;
	// 2와 5 카운팅
	pair<unsigned long long, unsigned long long> p1 = Counting(n); // n
	pair<unsigned long long, unsigned long long> p2 = Counting(m); // m
	pair<unsigned long long, unsigned long long> p3 = Counting(n - m); // n-m

	// 2와 5 중 더 적은 수를 출력
	cout << min(p1.first - p2.first - p3.first, p1.second - p2.second - p3.second);
	return 0;
}