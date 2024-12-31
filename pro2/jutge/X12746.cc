#include <iostream>
#include <map>
#include <string>
// Add more includes if you wish.
// ...

using namespace std;

int main() {
    // Declare and initialise more data if you wish.
    // ...

    map<int, int> v;
    int front_index = 0;
    int back_index = 0;

    string command;
    while (cin >> command) {
        if (command == "v.push_back(") {
            int val;
            cin >> val;
            string ending;
            cin >> ending;

            v[back_index] = val;
            back_index++;
        } else if (command == "v.push_front(") {
            int val;
            cin >> val;
            string ending;
            cin >> ending;  // Això consumeix el ");"

            front_index--;
            v[front_index] = val;
        } else if (command == "v.pop_front();") {
            v[front_index] = 0;
            front_index++;
        } else if (command == "v.pop_back();") {
            v[back_index] = 0;
            back_index--;
        } else if (command == "v.resize(") {
            int newsize;
            cin >> newsize;
            string ending;
            cin >> ending;  // Això consumeix el ");"

            back_index = front_index + newsize;
            auto it = v.rbegin();
            while (it != v.rend() and it->first >= back_index) {
                v.erase(it->first);
            }
        } else if (command == "cout<<v[") {
            int index;
            cin >> index;
            string ending;
            cin >> ending;  // Això consumeix el "];"

            cout << v[index + front_index] << endl;
        } else if (command == "cout<<v;") {
            cout << v[front_index];
            for (int i = front_index + 1; i < back_index; ++i) {
                cout << ',' << v[i];
            }
            cout << endl;
        } else if (command == "v[") {
            int index;
            cin >> index;
            string mid;
            cin >> mid;  // Això consumeix el "]="
            int val;
            cin >> val;
            string ending;
            cin >> ending;  // Això consumeix el ";"

            v[index + front_index] = val;
        } else if (command == "//") {
            string comment;
            getline(cin, comment);
            cout << "//" << comment << endl;
        } else {
            cout << "Wrong command '" << command << "'" << endl;
            string discard;
            getline(cin, discard);
        }
    }
}