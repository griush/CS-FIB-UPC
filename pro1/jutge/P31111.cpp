#include <iostream>
using namespace std;

int main()
{
	char current = ')';
	int count = 0;
	while (cin >> current)
	{
		if (current == '(') count++;
		else if (current == ')' && count == 0)
		{
			cout << "no" << endl;
			return 0;
		}
		else count--;
	}

	cout << ((count == 0) && current == ')' ? "yes" : "no") << endl;
}

