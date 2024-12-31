// Add or remove includes
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

int absolute(int x) {
    return x >= 0 ? x : -x;
}

/*
int positionDistance1(const vector<int> &v) {
    for (size_t i = 0; i < v.size() - 1; i++) {
        if (absolute(v[i] - v[i + 1]) == 1) return i;
    }

    return -1; // Unreachable
}
*/

int positionDistance1(const vector<int> &v) {
    size_t low = 0;
    size_t high = v.size() - 1;
    bool left_parity = v[0] % 2 == 0; // true if even, false if odd
    
    while (low < high) {
        size_t mid = low + (high - low) / 2;
        
        if (absolute(v[mid] - v[mid + 1]) == 1) return mid;

        bool mid_parity = v[mid] % 2 == 0;

        if (left_parity == mid_parity) low = mid;
        else high = mid;
    }

    return -1; // Unreachable
}

int main()  {
    vector<vector<int> > listinputs;
    vector<int> listsolutions;
    vector<int> listattempts;
    int n;
    while (cin >> n) {
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        listinputs.push_back(v);
        listsolutions.push_back(0);
    }
    int repetitions = max(1, 100000/int(listinputs.size()));
    for (int index = 0; index < int(listinputs.size()); index++)
        for (int i = 0; i < repetitions; i++)
            listattempts.push_back(index);
    random_shuffle(listattempts.begin(), listattempts.end());
    for (int r = 0; r < int(listattempts.size()); r++) {
        int i = listattempts[r];
        listsolutions[i] = positionDistance1(listinputs[i]);
    }
    for (int i = 0; i < int(listsolutions.size()); i++)
        cout << listsolutions[i] << endl;
}
