#include <iostream>
using namespace std;

//int main()
//{
//	int a, b;
//	cin >> a >> b;
//
//	int i = b % 10; // 1의 자리
//	int j = b % 100 - i; // 10의 자리
//	int k = b % 1000 - (i + j); // 100의 자리
//
//	cout << a * i << endl;
//	cout << a * (j / 10) << endl;
//	cout << a * (k / 100) << endl;
//	cout << a * b << endl;
//
//	return 0;
//}

#include <iostream>
int main() {
	int a = 472, b = 385;
	int ans1, ans2, ans3;
	ans1 = a * (b % 10);
	ans2 = a * ((b % 100) / 10);
	ans3 = a * (b / 100);
	scanf("%d %d", &a, &b);
	printf("%d\n", ans1);
	printf("%d\n", ans2);
	printf("%d\n", ans3);
	printf("%d\n", a*b);
}