#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int zero = 0;
    for (int i = 0; i < n; i++) {
        zero += s[i] == '0';
    }
    if (zero * 2 == n) {
        cout << "2\n";
        cout << s[0] << " ";
        for (int i = 1; i < n; i++) {
            cout << s[i];
        }
    } else {
        cout << "1\n" << s;
    }
}