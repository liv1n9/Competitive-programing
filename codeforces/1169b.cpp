#include <bits/stdc++.h>
using namespace std;

bool calc(vector<pair<int, int> > &a, int x) {
    int pre = -1;
    int m = 0;
    map<int, int> fre;
    for (auto &i: a) {
        if (i.first == x || i.second == x) continue;
        m++;
        fre[i.first]++;
        if (i.second != i.first) {
            fre[i.second]++;
        }
    }
    for (auto &i: fre) {
        if (i.second == m) {
            return true;
        }
    }
    return m == 0;
}

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > a(m);
    for (auto &i: a) {
        cin >> i.first >> i.second;
    }
    if (calc(a, a[0].first) || calc(a, a[0].second)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}