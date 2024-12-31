#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);

    for (size_t i = 0; i < nums.size(); i++) {
        // Fill the vector
        int x;
        cin >> x;
        nums[i] = x;
    }

    int result = 0;
    int index = 0;
    char c;
    while (cin >> c)
    {
        if (c == '+') result += nums.at(index);
        else if (c == '-') result -= nums.at(index);

	index++;
	if (index == n) {
	    index = 0;
	    cout << result << endl;
	    result = 0;
        }
    }

    return 0;
}
