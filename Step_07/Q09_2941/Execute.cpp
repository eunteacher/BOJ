/*
문제
예전에는 운영체제에서 크로아티아 알파벳을 입력할 수가 없었다. 따라서, 다음과 같이 크로아티아 알파벳을 변경해서 입력했다.

크로아티아 알파벳	변경
č	c=
ć	c-
dž	dz=
đ	d-
lj	lj
nj	nj
š	s=
ž	z=
예를 들어, ljes=njak은 크로아티아 알파벳 6개(lj, e, š, nj, a, k)로 이루어져 있다. 단어가 주어졌을 때, 몇 개의 크로아티아 알파벳으로 이루어져 있는지 출력한다.

dž는 무조건 하나의 알파벳으로 쓰이고, d와 ž가 분리된 것으로 보지 않는다. lj와 nj도 마찬가지이다. 위 목록에 없는 알파벳은 한 글자씩 센다.

입력
첫째 줄에 최대 100글자의 단어가 주어진다. 알파벳 소문자와 '-', '='로만 이루어져 있다.

단어는 크로아티아 알파벳으로 이루어져 있다. 문제 설명의 표에 나와있는 알파벳은 변경된 형태로 입력된다.

출력
입력으로 주어진 단어가 몇 개의 크로아티아 알파벳으로 이루어져 있는지 출력한다.
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
	// 입력 단어
	string input;
	// 크로아티아 알파벳
	string as[] = { "c=", "c-", "dz=", "d-", "lj", "nj","s=","z=" };
	getline(cin, input);
	// 입력받은 글자의 길이
	int length = input.length();
	int count = 0; // 결과

	for (int i = 0; i < length; i++)
	{
		bool b = false;

		// 인덱스 + 1가 배열의 길이보다 크거나 같다면, 1글자
		if (i + 1 >= length)
		{
			count++;
			continue;
		}

		// 현재 인덱스에 해당하는 문자 + 다음 인덱스에 해당하는 문자 -> 총 2글자 확인
		string temp;
		temp.push_back(input[i]);
		temp.push_back(input[i + 1]);

		for (string a : as)
		{
			if (temp == a)
			{
				count++;
				b = true;
				i += 1;
				continue;
			}
		}

		// 위에서 찾았으면 더 이상 찾을 필요가 없다.
		if (b == true)
		{
			continue;
		}

		// 인덱스 + 2가 배열의 길이보다 크거나 같다면, 1글자
		if (i + 2 >= length)
		{
			count++;
			continue;
		}

		// 현재 인덱스에 해당하는 문자 + 다음 인덱스에 해당하는 문자 + 다다음 인덱스에 해당하는 문자 -> 총 3글자 확인
		temp.push_back(input[i + 2]);

		for (string a : as)
		{
			if (temp == a)
			{
				count++;
				b = true;
				i += 2;
				continue;
			}
		}

		// 위에서 찾았으면 더 이상 찾을 필요가 없다.
		if (b == true)
		{
			continue;
		}

		// 1글자
		count++;
	}

	cout << count;

	return 0;
}

