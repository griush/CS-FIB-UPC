#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[i] = x;
    }
    
    int count = 0;
    for (size_t i = 0; (i < v.size() - 1) && v.size() > 1; i++)
    {
        if (v.at(i) == v.at(v.size() - 1))
            count++;
    }
    
    cout << count << endl;
    return 0;
}
