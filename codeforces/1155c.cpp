#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<ll> x(n);
    for (ll &i: x) {
        cin >> i;
    }
    sort(x.begin(), x.end());
    ll dis = x[1] - x[0];
    for (int i = 2; i < n; i++) {
        dis = __gcd(dis, x[i] - x[i - 1]);
    }
    for (int i = 1; i <= m; i++) {
        ll p;
        cin >> p;
        if (dis % p == 0) {
            cout << "YES\n";
            cout << x[0] << " " << i;
            return 0;
        }
    }
    cout << "NO";

}