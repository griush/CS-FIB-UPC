#include <iostream>
using namespace std;

int main()
{
	int i;
	cin >> i;

	int curr_index = 1;
	
	int current;
	while(cin >> current)
	{
		if (curr_index == i)
		{
			cout << "At the position " << i << " there is a(n) " << current << "." << endl;
			return 0;
		}

		curr_index++;
	}

	cout << "Incorrect position." << endl;
}
