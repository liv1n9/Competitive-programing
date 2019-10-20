#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 8;

int f[N][20];
int a[N];
int n, k;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    k = log2(n) + 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    int d = 1;
    for (int j = 1; j <= k; j++) {
        d *= 2;
        for (int i = d; i <= n; i++) {
            f[i][j] = f[i - d][j] + (int) ((a[i] - a[i - d]) % 10 > 0);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        long long res = 0;
        for (int j = 1; j <= k; j++) {
            res += f[r][j] - f[l - 1][j];
        }
        cout << res << endl;
    }
}