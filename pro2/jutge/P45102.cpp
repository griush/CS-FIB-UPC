#include <iostream>
using namespace std;

char nextToken() {
	char c = ' ';
	while (c == ' ') {
		cin >> c;
	}

	return c;
}

bool isNumber(char c) {
	return c >= '0' && c <= '9'; 
}

int eval(int n1, char op, int n2) {
	if (op == '+') {
		return n1 + n2;
	}
	if (op == '-') {
		return n1 - n2;
	}

	return n1 * n2;
}

int primary();

int expression() {
	int n1 = primary();
	char op = nextToken();
	int n2 = primary();

	nextToken(); // consume ')'

	return eval(n1, op, n2);
}

int primary() {
	char c = nextToken();
	if (isNumber(c)) return c - '0';
	if (c == '(') return expression(); 

	return -1; // Unreachable because of problem conditions
}

int main() {
	int result = primary(); // ( 3 + 4 )
	cout << result << endl;
}
