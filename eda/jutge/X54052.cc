#include <iostream>
#include <vector>
using namespace std;
int n;
vector<pair<char, char>> adn;
int letters[] = {'A', 'C', 'G', 'T'};

char match(char c) {
    switch (c) {
        case 'A':
            return 'T';
        case 'T':
            return 'A';
        case 'C':
            return 'G';
        case 'G':
            return 'C';
        default:
            return '.';  // unreachable
    }
}

void print() {
    for (int i = 0; i < n; i++) {
        cout << adn[i].first;
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << adn[i].second;
    }
    cout << endl << endl;
}

void bt(int i) {
    if (i == n) {
        print();
        return;
    }

    if (adn[i].first != '.') {
        adn[i].second = match(adn[i].first);
        bt(i + 1);
    } else if (adn[i].second != '.') {
        adn[i].first = match(adn[i].second);
        bt(i + 1);
    } else {
        for (int j = 0; j < 4; j++) {
            adn[i].first = letters[j];
            adn[i].second = match(letters[j]);
            bt(i + 1);
            adn[i].first = '.';
            adn[i].second = '.';
        }
    }
}

int main() {
    while (cin >> n) {
        bool valid = true;
        adn = vector<pair<char, char>>(n);
        for (int i = 0; i < n; i++) {
            cin >> adn[i].first;
        }
        for (int i = 0; i < n; i++) {
            cin >> adn[i].second;
            if (adn[i].second != '.' and adn[i].first != '.' and
                adn[i].second != match(adn[i].first))
                valid = false;
        }

        if (valid) bt(0);
        cout << "----------" << endl;
    }
}
