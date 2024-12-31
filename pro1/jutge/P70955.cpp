#include <iostream>
using namespace std;

int main() {
    constexpr int yearToSec = 365 * 24 * 3600;
    constexpr int dayToSec = 24 * 3600;
    constexpr int hourToSec = 3600;
    constexpr int minToSec = 60;

    int y, d, h, m, s;
    cin >> y >> d >> h >> m >> s;

    int totalSeconds = y * yearToSec + d * dayToSec + h * hourToSec + m * minToSec + s;
    cout << totalSeconds << endl;

    return 0;
}
