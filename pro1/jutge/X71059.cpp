#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Worker {
    string name;
    int score;
    bool country;  // true for israel, false for palesitne
};

int main() {
    // k: team member count
    int k;
    while (cin >> k) {

        // Input reading
        int n1;
        cin >> n1;

        vector<Worker> israel(n1);
        for (int i = 0; i < n1; i++) {
            cin >> israel[i].name >> israel[i].score;
            israel[i].country = true;
        }

        int n2;
        cin >> n2;

        vector<Worker> palestine(n2);
        for (int i = 0; i < n2; i++) {
            cin >> palestine[i].name >> palestine[i].score;
            palestine[i].country = false;
        }
        
        vector<Worker> workers(n1 + n2);
        merge(israel.begin(), israel.end(), palestine.begin(), palestine.end(), workers.begin(),
            [](const Worker& w1, const Worker& w2) {
                // First criteria: score
                if (w1.score != w2.score) {
                    return w1.score > w2.score;
                }

                // Third criteria: name
                if (w1.country == w2.country) {
                    return w1.name < w2.name;
                }

                // Second criteria: country
                return w1.country == w2.country;
            });

        for (const auto& worker : workers) {
            cout << worker.name << " " << worker.score << " " << (worker.country ? "israel" : "palestine") << endl;
        }

        endl(cout);
    }


    return 0;
}
