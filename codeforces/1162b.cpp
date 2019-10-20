#include <bits/stdc++.h>
using namespace std;

const int N = 58;

int a[N][N], b[N][N], c[N][N], d[N][N];
int n, m;

bool ok() {
    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            if (c[i][j - 1] >= c[i][j] || d[i][j - 1] >= d[i][j]) {
                return false;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 2; j <= n; j++) {
            if (c[j - 1][i] >= c[j][i] || d[j - 1][i] >= d[j][i]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> b[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        c[i][1] = a[i][1];
        d[i][1] = b[i][1];
        if (c[i][1] > d[i][1]) swap(c[i][1], d[i][1]);
        for (int j = 2; j <= m; j++) {
            if (a[i][j] > b[i][j]) {
                swap(a[i][j], b[i][j]);
            }
            if (a[i][j] > c[i][j - 1]) {
                c[i][j] = a[i][j];
                d[i][j] = b[i][j];
            } else {
                c[i][j] = b[i][j];
                d[i][j] = a[i][j];
            }
        }
    }
    cout << (ok() ? "Possible" : "Impossible");
}