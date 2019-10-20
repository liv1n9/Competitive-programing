#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int f[1 << 15][15];

int n, m;
int t[15], g[15];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> g[i];
        f[1 << i][i] = 1;
    }
    for (int state = 1; state < (1 << n); state++) {
        for (int i = 0; i < n; i++) {
            if ((state >> i) & 1) {
                for (int j = 0; j < n; j++) {
                    if ((state >> j) % 2 == 0 && g[j] != g[i]) {
                        int &_f = f[state | (1 << j)][j];
                        _f += f[state][i];
                        if (_f >= MOD) _f -= MOD;
                    }
                }
            }
        }
    }
    int res = 0;
    for (int state = 1; state < (1 << n); state++) {
        for (int i = 0; i < n; i++) {
            int v = 0;
            for (int j = 0; j < n; j++) {
                if ((state >> j) & 1) {
                    v += t[j];
                }
            }
            if (v == m) {
                res += f[state][i];
                if (res >= MOD) {
                    res -= MOD;
                }
            }
        }
    }
    cout << res;
}