#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> a;

int Find(int x, int l, int r) {
    int res = -1;
    while (l <= r) {
        int m = (l + r) >> 1;
        if (a[m] <= x) {
            res = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    a.resize(n);
    for (auto &i: a) cin >> i;
    sort(a.begin(), a.end());
    ll res = 0;
    int l = 1;
    while (l < n && a[l] < 0) {
        l++;
    }
    for (int i = 0; i < n; i++) {
        l = max(l, i + 1);
        int j = Find(abs(a[i]) * 2, l, n - 1);
        if (j != -1) {
            res += j - l + 1;
        }
    }
    cout << res;
}