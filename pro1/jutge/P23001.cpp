#include <iostream>
using namespace std;

int main()
{
	string first;
	cin >> first;

	int max_sequence = 1, curr_sequence = 1;

	string current;
	while (cin >> current)
	{
		if (current == first)
		{
			curr_sequence++;
			if (curr_sequence > max_sequence)
				max_sequence = curr_sequence;
			continue;
		}

		curr_sequence = 0;
	}

	cout << max_sequence << endl;
}

