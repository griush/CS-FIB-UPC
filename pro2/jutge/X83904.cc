#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, int> players;

    string name;
    cin >> name;

    while (name != ".") {
        players[name] = 0;
        cin >> name;
    }

    int num_activities;
    cin >> num_activities;

    for (int i = 0; i < num_activities; i++) {
        cin >> name;

        while (name != ".") {
            players[name]++;

            cin >> name;
        }
    }

    cout << "Totes les activitats:";
    for (auto it : players) {
        if (it.second == num_activities) cout << ' ' << it.first;
    }
    cout << "\nCap activitat:";
    for (auto it : players) {
        if (it.second == 0) cout << ' ' << it.first;
    }

    return 0;
}