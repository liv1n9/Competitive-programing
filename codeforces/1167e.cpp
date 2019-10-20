#include <bits/stdc++.h>
using namespace std;

int Find(int x, int l, int r, vector<pair<int, int> > &a) {
    int res;
    while (l <= r) {
        int m = (l + r) >> 1;
        if (a[m].first > x) {
            res = a[m].first;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return res;
}

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    vector<int> a(n);
    vector<vector<int> > b(x);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[a[i]].push_back(i);
    }
    long long res = 0;
    vector<pair<int, int> > l(1, {0, -1});
    vector<pair<int, int> > r(1, {x + 1, n});
    int last = -1;
    for (int i = 1; i <= x; i++) {
        int cur = INT_MAX;
        int bo = -1;
        for (int j: b[i]) {
            cur = min(cur, j);
            bo = max(bo, j);
        }
        if (cur > last) {
            if (bo == -1) {
                bo = last;
            }
            l.push_back({i, bo});
        }
        if (cur < INT_MAX) {
            last = cur;
        }
    }
    last = INT_MAX;
    for (int i = x; i >= 1; i--) {
        int cur = -1;
        int bo = INT_MAX;
        for (int j: b[i]) {
            cur = max(cur, j);
            bo = min(bo, j);
        }
        if (cur < last) {
            if (bo == INT_MAX) {
                bo = last;
            }
            r.push_back({i, bo});
        }
        if (cur > -1) {
            last = cur;
        }
    }
    int pos = 0;
    for (auto &e: l) {
        while (pos < r.size() && r[pos].second <= e.second) {
            pos++;
        }
        long long tmp = Find(e.first, pos, (int)r.size() - 1, r) - e.first - 1;
        res += tmp * (tmp + 1) / 2;
    }
    cout << res;
}