#include <bits/stdc++.h>
using namespace std;

bool is_expression(char c) {
    return c == 'x' || c == 'X' || c == '0' || c == '1';
}

bool is_operator(char c) {
    return c == '&' || c == '|' || c == '^';
}

char calculate(char x, char op, char y) {
    if (x == '0' || x == '1') {
        swap(x, y);
    }
    if (op == '&') {
        if (y == '0') {
            return '0';
        }
        if (y == '1') {
            return x;
        }
        return x != y ? '0' : x;
    }
    if (op == '|') {
        if (y == '0') {
            return x;
        }
        if (y == '1') {
            return '1';
        }
        return x != y ? '1' : x;
    }
    if (op == '^') {
        if (y == '0') {
            return x;
        }
        if (y == '1') {
            if (x == '0') return '1';
            if (x == '1') return '0';
            return x == 'x' ? 'X' : 'x';
        }
        return x != y ? '1' : '0';
    }
}

int main() {
    int test;
    cin >> test;
    for (int i = 1; i <= test; i++) {
        string s;
        cin >> s;
        stack<char> value, opt;
        for (int i = 0; i < s.size(); i++) {
            if (is_expression(s[i])) {
                value.push(s[i]);
            } else if (is_operator(s[i])) {
                opt.push(s[i]);
            } else if (s[i] == ')') {
                char y = value.top();
                value.pop();
                char op = opt.top();
                opt.pop();
                value.top() = calculate(value.top(), op, y);
            }
        }
        cout << "Case #" << i << ": " << ((value.top() == '0' || value.top() == '1') ? "0\n" : "1\n");
    }
}