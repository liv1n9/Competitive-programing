#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 3e5 + 8;
ll f[N][2];
ll a[N];

int main() {
    ios::sync_with_stdio(false);
    int n;
    ll x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll past = 0, sum = 0;
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
        f[i][0] = max(0ll, sum - past);
        f[i][1] = max(f[i - 1][0], f[i - 1][1]) + a[i] * x;
        past = min(past, sum);
        res = max(res, f[i][0]);
    }
    res = max(res, f[n][1]);
    past = 0, sum = 0;
    for (int i = n; i >= 1; i--) {
        sum += a[i];
        res = max(res, max(0ll, sum - past) + f[i - 1][1]);
        past = min(past, sum);
    }
    cout << res;
}