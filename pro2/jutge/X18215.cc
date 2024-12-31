#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 0 last, 1 is the one before last, and so on
#define at_from_back(x, i) (x[x.size() - (i + 1)])

string parse_solution(const string& input) {
    vector<char> stack;

    for (size_t i = 0; i < input.length() - 1; i++) {
        char c = input[i];
        stack.push_back(c);

        while (true) {
            if (at_from_back(stack, 0) == 'n') {
                stack.pop_back();
                stack.push_back('E');
            } else if (at_from_back(stack, 0) == 'v' and input[i + 1] != '=') {
                stack.pop_back();
                stack.push_back('E');
            } else if (stack.size() >= 3 and at_from_back(stack, 0) == 'E' and
                       at_from_back(stack, 1) == '*' and
                       at_from_back(stack, 2) == 'E') {
                stack.pop_back();
                stack.pop_back();
            } else if (stack.size() >= 3 and at_from_back(stack, 0) == 'E' and
                       at_from_back(stack, 1) == '+' and
                       at_from_back(stack, 2) == 'E' and input[i + 1] != '*') {
                stack.pop_back();
                stack.pop_back();
            } else if (stack.size() >= 3 and at_from_back(stack, 0) == 'E' and
                       at_from_back(stack, 1) == '<' and
                       at_from_back(stack, 2) == 'E' and
                       (input[i + 1] != '*' and input[i + 1] != '+')) {
                stack.pop_back();
                stack.pop_back();
            } else if (stack.size() >= 4 and at_from_back(stack, 0) == ';' and
                       at_from_back(stack, 1) == 'E' and
                       at_from_back(stack, 2) == '=' and
                       at_from_back(stack, 3) == 'v') {
                stack.pop_back();
                stack.pop_back();
                stack.pop_back();
                stack.pop_back();
                stack.push_back('I');
            } else if (stack.size() >= 4 and at_from_back(stack, 0) == ')' and
                       at_from_back(stack, 1) == 'E' and
                       at_from_back(stack, 2) == '(' and
                       (at_from_back(stack, 3) != 'i' and
                        at_from_back(stack, 3) != 'w')) {
                stack.pop_back();
                stack.pop_back();
                stack.pop_back();
                stack.push_back('E');
            } else if (stack.size() >= 5 and at_from_back(stack, 0) == 'I' and
                       at_from_back(stack, 1) == ')' and
                       at_from_back(stack, 2) == 'E' and
                       at_from_back(stack, 3) == '(' and
                       at_from_back(stack, 4) == 'i' and input[i + 1] != 'e') {
                stack.pop_back();
                stack.pop_back();
                stack.pop_back();
                stack.pop_back();
                stack.pop_back();
                stack.push_back('I');
            } else if (stack.size() >= 7 and at_from_back(stack, 0) == 'I' and
                       at_from_back(stack, 1) == 'e' and
                       at_from_back(stack, 2) == 'I' and
                       at_from_back(stack, 3) == ')' and
                       at_from_back(stack, 4) == 'E' and
                       at_from_back(stack, 5) == '(' and
                       at_from_back(stack, 6) == 'i') {
                stack.pop_back();
                stack.pop_back();
                stack.pop_back();
                stack.pop_back();
                stack.pop_back();
                stack.pop_back();
                stack.pop_back();
                stack.push_back('I');
            } else if (stack.size() >= 5 and at_from_back(stack, 0) == 'I' and
                       at_from_back(stack, 1) == ')' and
                       at_from_back(stack, 2) == 'E' and
                       at_from_back(stack, 3) == '(' and
                       at_from_back(stack, 4) == 'w') {
                stack.pop_back();
                stack.pop_back();
                stack.pop_back();
                stack.pop_back();
                stack.pop_back();
                stack.push_back('I');
            } else if (stack.size() >= 2 and at_from_back(stack, 0) == 'I' and
                       at_from_back(stack, 1) == 'L') {
                stack.pop_back();
            } else if (at_from_back(stack, 0) == 'I' and stack.size() >= 2 and
                       (at_from_back(stack, 1) != ')' and
                        at_from_back(stack, 1) != 'L')) {
                stack.pop_back();
                stack.push_back('L');
            } else if (at_from_back(stack, 0) == 'I' and stack.size() == 1) {
                stack.pop_back();
                stack.push_back('L');
            } else if (stack.size() >= 3 and at_from_back(stack, 0) == '}' and
                       at_from_back(stack, 1) == 'L' and
                       at_from_back(stack, 2) == '{') {
                stack.pop_back();
                stack.pop_back();
                stack.pop_back();
                stack.push_back('I');
            } else if (input[i + 1] == ' ' and stack.size() == 1 and
                       at_from_back(stack, 0) == 'L') {
                stack.pop_back();
                stack.push_back('P');
            } else {
                break;
            }
        }
    }

    return string(stack.begin(), stack.end());
}

int main() {
    string in;
    while (cin >> in) {
        // Triquiñuela per accedir a posicio final d'string sense out_of_bounds
        // Se que no es elegant pero es complica una miqueta les condicions i
        // es inecessari complicar ja que el codi no ha d'escalar.
        in.append(" ");
        cout << parse_solution(in) << endl;
    }
}