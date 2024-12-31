#include <iostream>
using namespace std;

int main() {
    int year;
    cin >> year;

    bool isLeapYear = true;
    if (year % 4 != 0) {
        isLeapYear = false;
    }

    if (year % 100 == 0) {
        isLeapYear = false;
    }

    if (year % 400 == 0) {
        isLeapYear = true;
    }

    if (isLeapYear)
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;

    return 0;
}
