#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 8;
string s[N];
int r[N], c[N];

int sum(int x, int y) {
    return r[x] + c[y] - (int)(s[x][y] == '.');
}

int main() {
    ios::sync_with_stdio(false);
    int q;
    cin >> q;
    while (q--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> s[i];
            for (int j = 0; j < m; j++) {
                int p = (int)(s[i][j] == '.');
                r[i] = i == 0 ? p : r[i - 1] + p;
                c[j] = j == 0 ? p : c[j - 1] + p;
            }
        }
        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res = min(res, sum(i, j));
                if (i == 2 && j == 2) {
                    cerr << i << " " << j << " " << sum(i, j) << endl;
                }
            }
        }
        cout << res << endl;
    }
}