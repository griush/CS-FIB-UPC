#include <iostream>
using namespace std;

int main()
{
	int happiness = 0;
	int sadness = 0;

	char prev_useful = 0;
	int dash = 0;

	char current; 
	while (cin >> current)
	{
		if (current == ':')
		{
			if (prev_useful == '(' && dash == 1) happiness++;
			else if (prev_useful == ')' && dash == 1) sadness++;
			prev_useful = current;
			dash = 0;
		}
		else if (current == '(')
		{
			if (prev_useful == ':' && dash == 1) sadness++;
			prev_useful = current;
			dash = 0;
		}
		else if (current == ')')
		{
			if (prev_useful == ':' && dash == 1) happiness++;
			prev_useful = current;
			dash = 0;
		}
		else if (current == '-')
		{
			dash++;
		}


	}

	cout << happiness << " " << sadness << std::endl;

	return 0;
}
