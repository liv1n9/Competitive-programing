#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, m, k;

ll page(ll x) {
    return (x + k - 1) / k;
}

int main() {
    cin >> n >> m >> k;
    vector<ll> a(m);
    for (ll &i: a) {
        cin >> i;
    }
    ll pre = -1;
    ll t = 0;
    int res = 0;
    ll p = 0;
    for (int i = 0; i < m; i++) {
        ll cur = page(a[i] - p);
        if (pre == -1 || pre == cur) {
            t++;
            pre = cur;
        } else {
            res++;
            p += t;
            t = 0;
            pre = -1;
            i--;
        }
    }
    if (t > 0) res++;
    cout << res;
}