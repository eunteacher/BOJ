#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x;
	cin >> x;

	for (int i = 1; i < x + 1; i++) // ¼¼·Î
	{
		for (int j = x - 1; j > i - 1; j--)
		{
			cout << " ";
		}

		for (int k = 0; k < i; k++)
		{
			cout << "*";
		}

		cout << '\n';
	}

	return 0;
}