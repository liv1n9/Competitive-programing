#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    ll v = b - a;
    vector<ll> d;
    for (ll i = 1; i * i <= v; i++) {
        if (v % i == 0) {
            d.push_back(i);
            if (v / i != i) {
                d.push_back(v / i);
            }
        }
    }
    sort(d.begin(), d.end());
    ll large = __gcd(a, b);
    ll res = 0;
    for (ll i: d) {
        if (a % i == b % i) {
            ll r = a % i;
            if ((b - r) / i - (a - r) / i == v / i) {
                ll k = (i - r) % i;
                ll gd = __gcd(a + k, b + k);
                if ((a + k) / gd <= large / (b + k)) {
                    ll temp = (a + k) / gd * (b + k);
                    if (temp < large) {
                        res = k;
                    } else if (temp == large) {
                        res = min(res, k);
                    }
                    large = temp;
                }
            }
        }
    }
    cout << res;
}