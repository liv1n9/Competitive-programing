#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > a[2];
vector<pair<int, int> > b[2];

int c[1008];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, l, r;
        cin >> x >> l >> r;
        a[x].push_back({l, r});
    }
    for (int i = 0; i < 2; i++) {
        sort(a[i].begin(), a[i].end());
    }
    for (int x = 1; x <= 1; x++) {
        for (int i = 0; i < a[x].size(); i++) {
            if (i == 0 || a[x][i].first > b[x].back().second) {
                b[x].push_back(a[x][i]);
            } else {
                b[x].back().second = max(b[x].back().second, a[x][i].second);
            }
        }
    }
    int first = 1e6;
    for (auto &p: b[1]) {
        first -= 8888;
        for (int i = p.first; i <= p.second; i++) {
            c[i] = ++first;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (c[i] == 0) {
            if (i == 1) {
                first == 1e8;
            } else {
                first = c[i - 1] - 1;
            }
            c[i] = first;
        }
    }
    for (auto &p: a[0]) {
        bool ok = false;
        for (int i = p.first + 1; i <= p.second ;i++) {
            if (c[i] < c[i - 1]) {
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        cout << c[i] << " ";
    }
}