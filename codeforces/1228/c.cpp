#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
ll res = 1;

ll powr(ll a, ll x) {
    if (x == 0) return 1;
    ll d = powr(a, x >> 1);
    d = (d * d) % MOD;
    if (x & 1) return (d * a) % MOD;
    return d;
}

void calc(ll i, ll n) {
    ll p = 0;
        ll d = 1;
        ll e = 1;
        while (d <= n / i) {
            d *= i;
            p++;
        }
        for (int k = p; k >= 1; k--) {
            ll t = n / d;
            if (k < p) {
                t -= n / (d * i);
            }
            e = (e * powr(d % MOD, t)) % MOD;
            d /= i;
        }
        // cerr << i << " " << e << endl;
        res = (res * e) % MOD;
}

int main() {
    ll x, n;
    cin >> x >> n;
    ll r = sqrt(x) + 1;
    for (ll i = 2; i <= r; i++) {
        if (x % i == 0) {
            while (x % i == 0) {
                x /= i;
            }
            calc(i, n);
        }
    }
    if (x > 1) {
        calc(x, n);
    }
    cout << res;
}