#include <functional>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

// global pattern
string compare_pattern;

/// Returns true if b should be before a
bool compare(string a, string b) {
    if (a.length() != b.length()) {
        return a.length() > b.length();
    }

    return
}

void calculateTickets(string pattern) {
    compare_pattern = pattern;
    string in;
    cin >> in;

    int ticket_count = 0;
    priority_queue<string, vector<string>, function<bool(string, string)>>
        member_q(compare);
    while (in != "E") {
        if (in == "T") {
            ticket_count++;
        } else if (in == "S") {
            string code;
            cin >> code;
            member_q.push(code);

            std::priority_queue<string, vector<string>,
                                function<bool(string, string)>>
                pq_copy = member_q;

            // Print elements from the copy without modifying the original queue
            while (!pq_copy.empty()) {
                std::cout << pq_copy.top() << " ";
                pq_copy.pop();
            }

            endl(cout);
            cout << member_q.top() << endl;
        }

        cin >> in;
    }
}

int main() {
    string in;
    while (cin >> in) {
        calculateTickets(in);
    }
}
