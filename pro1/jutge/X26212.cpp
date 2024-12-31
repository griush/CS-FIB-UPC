#include <iostream>
#include <vector>
using namespace std;

inline char get_at(const vector<char>& v, int x, int y, int w) {
    // Maybe do bounds check here (caller manages this)
    return v[x + y * w];
}

int happy_faces(int w, int h) {
    int count = 0;
    bool do_vert = true;

    vector<char> m;
    m.reserve(w * h);
    for (int i = 0; i < w * h; i++) {
        char c;
        cin >> c;
        m.push_back(c);
    }

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            do_vert = true;
            // Check for horz faces
            if ((w - x) >= 3) {
                if ((get_at(m, x, y, w) == '(' &&
                     get_at(m, x + 1, y, w) == '-' &&
                     get_at(m, x + 2, y, w) == ':') ||
                    (get_at(m, x, y, w) == ':' &&
                     get_at(m, x + 1, y, w) == '-' &&
                     get_at(m, x + 2, y, w) == ')')) {
                    count++;
                    x += 1;
                    do_vert = false;
                }
            }

            // Check for vertical faces
            if (((h - y) >= 3) && do_vert) {
                if ((get_at(m, x, y, w) == '^' &&
                     get_at(m, x, y + 1, w) == '|' &&
                     get_at(m, x, y + 2, w) == '\"') ||
                    (get_at(m, x, y, w) == '\"' &&
                     get_at(m, x, y + 1, w) == '|' &&
                     get_at(m, x, y + 2, w) == 'v')) {
                    count++;
                }
            }
        }
    }

    return count;
}

int main() {
    int width, height;
    while (cin >> height >> width) {
        cout << happy_faces(width, height) << endl;
    }
}
