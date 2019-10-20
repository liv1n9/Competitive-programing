#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<pair<char, int> > t;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != 'a') {
            t.push_back({s[i], i});
        }
    }
    if (t.size() & 1) {
        cout << ":(";
    } else {
        int m = t.size() / 2;
        bool ok = true;
        for (int i = 0; i < m; i++) {
            if (t[i].first != t[m + i].first) {
                ok = false;
                break;
            }
        }
        if (t.empty()) {
            t.push_back({'v', s.size()});
        }
        for (int i = t[m].second; i < s.size(); i++) {
            if (s[i] == 'a') {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << ":(";
        } else {
            for (int i = 0; i < t[m].second; i++) {
                cout << s[i];
            }
        }
    }
}