#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string a;
        string b;
        cin >> a >> b;
        vector<pair<char, int> > c, d;
        for (int i = 0; i < a.size(); i++) {
            if (i == 0 || a[i] != a[i - 1]) {
                c.push_back({a[i], 1});
            } else {
                c.back().second++;
            }
        }
        for (int i = 0; i < b.size(); i++) {
            if (i == 0 || b[i] != b[i - 1]) {
                d.push_back({b[i], 1});
            } else {
                d.back().second++;
            }
        }
        bool ok = true;
        if (d.size() != c.size()) {
            ok = false;
        }
        for (int i = 0; i < c.size(); i++) {
            if (c[i].first != d[i].first || c[i].second > d[i].second) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}