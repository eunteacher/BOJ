#include <iostream>
using namespace std;

double Division(double a, double b)
{
	return a / b;
}

int main()
{
	double x, y;
	cin >> x >> y;
	cout << fixed;
	cout.precision(9);
	cout << Division(x, y) << endl;
	return 0;
}