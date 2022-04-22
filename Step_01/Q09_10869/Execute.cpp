#include <iostream>
using namespace std;

void Operation(int a, int b)
{
	cout << a + b << endl;
	cout << a - b << endl;
	cout << a * b << endl;
	cout << a / b << endl;
	cout << a % b << endl;
}

int main()
{
	int a, b;
	cin >> a >> b;
	Operation(a, b);
	
	return 0;
}