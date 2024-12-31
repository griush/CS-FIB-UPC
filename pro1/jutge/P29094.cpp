#include <vector>
using namespace std;

int position_maximum(const vector<double>& v, int m) {
    int max_index = 0;
    for (int i = 0; i <= m; i++) {
        if (v[i] > v[max_index]) {
            max_index = i;
        }
    }

    return max_index;
}
