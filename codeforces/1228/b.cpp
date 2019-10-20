#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const int N = 1008;
int r[N], c[N];
int x[N], y[N];
int a[N][N];

ll powr(ll a, ll x) {
    if (x == 0) return 1;
    ll d = powr(a, x >> 1);
    d = (d * d) % MOD;
    if (x & 1) return (d * a) % MOD;
    return d;
}

int main() {
    #ifdef TANNHA
    freopen(".inp", "r", stdin);
    freopen(".out", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> r[i];
        for (int j = 1; j <= r[i]; j++) {
            a[i][j] = 1;
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> c[i];
        for (int j = 1; j <= c[i]; j++) {
            a[j][i] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        int x = 0;
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 0) {
                break;
            }
            x++;
        }
        if (x != r[i]) {
            cout << 0;
            return 0;
        }
    }
    for (int i = 1; i <= m; i++) {
        int x = 0;
        for (int j = 1; j <= n; j++) {
            if (a[j][i] == 0) {
                break;
            }
            x++;
        }
        if (x != c[i]) {
            cout << 0;
            return 0;
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int d = 0;
    int px[] = {0, 0, -1, 1};
    int py[] = {-1, 1, 0, 0};
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            if (a[i][j] == 0 && j > r[i] + 1 && i > c[j] + 1) {
                d++;
            }
        }
    }
    cout << powr(2, d);
}