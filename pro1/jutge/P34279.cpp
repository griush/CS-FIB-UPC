#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    int h, m, s;
    cin >> h >> m >> s;

    s++;
    if (s != 60) {
        stringstream ss;
        ss << setw(2) << setfill('0') << h << ":";
        ss << setw(2) << setfill('0') << m << ":";
        ss << setw(2) << setfill('0') << s;
        cout << ss.str() << endl;
        return 0;
    }

    s = 0;
    m++;
    if (m != 60) {
        stringstream ss;
        ss << setw(2) << setfill('0') << h << ":";
        ss << setw(2) << setfill('0') << m << ":";
        ss << setw(2) << setfill('0') << s;
        cout << ss.str() << endl;
        return 0;
    }

    m = 0;
    h++;
    if (h != 24) {
        stringstream ss;
        ss << setw(2) << setfill('0') << h << ":";
        ss << setw(2) << setfill('0') << m << ":";
        ss << setw(2) << setfill('0') << s;
        cout << ss.str() << endl;
        return 0;
    }

    h = 0;
    stringstream ss;
    ss << setw(2) << setfill('0') << h << ":";
    ss << setw(2) << setfill('0') << m << ":";
    ss << setw(2) << setfill('0') << s;
    cout << ss.str() << endl;
    return 0;

    return 0;
}
