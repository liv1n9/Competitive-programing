#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 8;

pair<ll, int> a[N];
int n;

bool avail(int j) {
    vector<ll> b;
    for (int i = 1; i <= n; i++) {
        if (i != j) {
            b.push_back(a[i].first);
        }
    }
    ll c = b[1] - b[0];
    bool ok = true;
    for (int i = 1; i < b.size(); i++) {
        if (b[i] != b[0] + c * i) {
            ok = false;
            break;
        }
    }
    return ok;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    if (n == 2) {
        cout << 1;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + 1 + n);
    if (avail(1)) {
        cout << a[1].second;
        return 0;
    }
    if (avail(2)) {
        cout << a[2].second;
        return 0;
    }

    int l = 1, r = n;
    int pos;
    while (l <= r) {
        int m = (l + r) >> 1;
        bool ok = true;
        if (m >= 2) {
            ll c = a[2].first - a[1].first;
            for (int i = 3; i <= m; i++) {
                if (a[i].first != a[1].first + c * (i - 1)) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) {
            pos = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    if (pos == n) {
        cout << 1;
        return 0;
    } 
    int res = a[pos + 1].second;
    cout << (avail(pos + 1) ? res : -1);
}