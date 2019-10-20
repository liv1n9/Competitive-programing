#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > a(m);
    vector<vector<int> > b(n);
    for (int i = 0; i < m; i++) {
        cin >> a[i].first >> a[i].second;
        if (a[i].first > a[i].second) swap(a[i].first, a[i].second);
        int len = a[i].second - a[i].first;
        if (len > n / 2) {
            swap(a[i].first, a[i].second);
            len = n - len;
        }
        b[len].push_back(i);
    }
    for (int i = 1; i <= n / 2; i++) {
        sort(b[i].begin(), b[i].end());
    }
    vector<int> temp;
    for (int i = 1; i <= n / 2; i++) {
        int pre = -1;
        for (int j = 0; j < b[i].size(); j++) {
            int k = (j + 1) % b[i].size();
            int diff;
            if (a[b[i][j]].first < a[b[i][k]].first) {
                diff = a[b[i][k]].first - a[b[i][j]].first;
            } else {
                diff = n + a[b[i][k]].first - a[b[i][j]].first;
            }
            if (pre == -1) {
                pre = diff;
            } else if (pre != diff) {
                cout << "No";
                return 0;
            }
        }
        temp.push_back(pre);
    }
    sort(temp.begin(), temp.end());
    if (temp.back() == n) {
        cout << "No";
        return 0;
    }
    for (int i = 0; i + 1 < temp.size(); i++) {
        if (temp.back() % temp[i] != 0) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}