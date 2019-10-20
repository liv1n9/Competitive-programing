#include <bits/stdc++.h>
using namespace std;

const int N = 1008;
char s[N][N];
int f[N][N][26];
int n, m;

bool single(int x, int y, int u, int v) {
    int cnt = 0;
    for (int k = 0; k < 26; k++) {
        int b = f[u][v][k] - f[u][y - 1][k] - f[x - 1][v][k] + f[x - 1][y - 1][k];
        if (b > 0) {
            cnt++;
            if (cnt > 1) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k < 26; k++) {
                f[i][j][k] = f[i - 1][j][k] + f[i][j - 1][k] - f[i - 1][j - 1][k] + (int)(s[i][j] - 'a' == k);
            }
        }
    }
    long long res = 0;
    for (int j = 1; j <= m; j++) {
        vector<pair<int, int> > a;
        for (int i = 1; i <= n; i++) {
            if (i == 1 || s[i][j] != s[i - 1][j]) {
                a.push_back({i, i});
            } else {
                a.back().second = i;
            }
        }
        for (int i = 2; i < a.size(); i++) {
            int x = a[i - 2].second - a[i - 2].first;
            int y = a[i - 1].second - a[i - 1].first;
            int z = a[i - 0].second - a[i - 0].first;
            char c1 = s[a[i - 2].first][j];
            char c2 = s[a[i - 1].first][j];
            char c3 = s[a[i - 0].first][j];
            if (x >= y && y <= z && c1 != c2 && c2 != c3) {
                int l = 0, r = m - j, temp;
                while (l <= r) {
                    int g = (l + r) >> 1;
                    bool s1 = single(a[i - 2].second - y, j, a[i - 2].second, j + g);
                    bool s2 = single(a[i - 1].first, j, a[i - 1].second, j + g);
                    bool s3 = single(a[i].first, j, a[i].first + y, j + g);
                    if (s1 && s2 && s3) {
                        temp = g;
                        l = g + 1;
                    } else {
                        r = g - 1;
                    }
                }
                res += temp + 1;
            }
        }
    }
    cout << res;
}