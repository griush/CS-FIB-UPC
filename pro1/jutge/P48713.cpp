#include <iostream>
using namespace std;

bool is_prime(int x)
{
	if (x <= 1) return false;
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;

	return true;
}

int main()
{
	int n;
	cin >> n;

	while (n > 0)
	{
		int x;
		cin >> x;

		cout << x << (is_prime(x) ? " is prime" : " is not prime") << endl;

		n--;
	}
}
