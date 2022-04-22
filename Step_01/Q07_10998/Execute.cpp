#include <iostream>
using namespace std;

int Mul(int a, int b)
{
	return a * b;
}

int main()
{
	int x = 0, y = 0;
	cin >> x >> y;
	cout << Mul(x, y) << endl;

	cin >> x >> y;
	cout << Mul(x, y) << endl;

	return 0;
}