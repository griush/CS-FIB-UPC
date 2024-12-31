#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Slot {
    vector<string> listsubjects;
    vector<string> listteachers;
};

typedef vector<vector<Slot> > TableSlots;

int day_to_number(const string& day) {
    if (day == "monday") return 0;
    if (day == "tuesday") return 1;
    if (day == "wednesday") return 2;
    if (day == "thursday") return 3;
    if (day == "friday") return 4;

    return -1;
}

string number_to_day(int day) {
    if (day == 0) return "monday";
    if (day == 1) return "tuesday";
    if (day == 2) return "wednesday";
    if (day == 3) return "thursday";
    if (day == 4) return "friday";

    return "unknown";
}

int num_of_digits(int n) {
    if (n == 0) return 1;
    return floor(log10(n) + 1);
}

inline void print_int_width(int n, int width) {
    int num_digits = num_of_digits(n);
    for (int i = 0; i < width - num_digits; i++) {
        cout << " ";
    }
    cout << n;
}

void print_table_subjects(const TableSlots& table, int first_hour,
                          int last_hour) {
    cout << "number of subjects per slot:" << '\n';
    cout << " h    monday   tuesday wednesday  thursday    friday\n";
    for (int i = first_hour; i < last_hour; i++) {
        if (i < 10) cout << " ";
        cout << i;
        for (int j = 0; j < 5; j++) {
            print_int_width(table[j][i].listsubjects.size(), 10);
        }
        cout << '\n';
    }
}

void print_table_teachers(const TableSlots& table, int first_hour,
                          int last_hour) {
    cout << "number of teachers per slot:" << '\n';
    cout << " h    monday   tuesday wednesday  thursday    friday\n";
    for (int i = first_hour; i < last_hour; i++) {
        if (i < 10) cout << " ";
        cout << i;
        for (int j = 0; j < 5; j++) {
            print_int_width(table[j][i].listteachers.size(), 10);
        }
        cout << '\n';
    }
}

int calculate_replacements(const TableSlots& table, int first_hour,
                           int last_hour) {
    int result = 0;
    for (int i = first_hour; i < last_hour; i++) {
        for (int j = 0; j < 5; j++) {
            if (table[j][i].listsubjects.size() > 1) {
                result += table[j][i].listsubjects.size() -
                          table[j][i].listteachers.size();
            }
        }
    }

    return result;
}

int main() {
    string subject, teacher, day_of_week_str;
    int start_hour, end_hour;

    TableSlots table(5, vector<Slot>(24));
    int first_hour = 24, last_hour = 0;

    // Get input
    while (cin >> subject >> teacher >> day_of_week_str >> start_hour >>
           end_hour) {
        int day_of_week = day_to_number(day_of_week_str);
        for (int i = start_hour; i < end_hour; ++i) {
            table[day_of_week][i].listsubjects.push_back(subject);
            auto& teachers = table[day_of_week][i].listteachers;
            auto it =
                std::lower_bound(teachers.begin(), teachers.end(), teacher);
            if (it == teachers.end() || *it != teacher) {
                teachers.insert(it, teacher);
            }
        }

        if (start_hour < first_hour) first_hour = start_hour;
        if (end_hour > last_hour) last_hour = end_hour;
    }

    print_table_subjects(table, first_hour, last_hour);
    print_table_teachers(table, first_hour, last_hour);

    cout << "number of replacements needed to avoid conflicts:\n";
    cout << calculate_replacements(table, first_hour, last_hour) << endl;

    return 0;
}
