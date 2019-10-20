#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    int n, m, k;
    ll ta, tb;
    cin >> n >> m >> ta >> tb >> k;
    vector<ll> a(n), b(m);
    vector<int> f(m);
    for (ll &i: a) cin >> i;
    for (ll &i: b) cin >> i;
    int j = 0;
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        while (j < a.size() && a[j] + ta <= b[i]) {
            cnt++;
            j++;
        }
        if (i == 0) {
            if (cnt == 0) f[i] == 0;
            else f[i] = 1;
        } else {
            f[i] = min(f[i - 1] + 1, cnt);
        }
    }
    ll res = -1;
    for (int i = 0; i < m; i++) {
        if (f[i] > k) {
            res = b[i] + tb;
            break;
        }
    }
    cout << res;
}