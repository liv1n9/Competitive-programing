#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        while (s.size() > 0 && s[0] != '8') {
            s.erase(0, 1);
        }
        cout << (s.size() >= 11 ? "YES\n" : "NO\n");
    }
}