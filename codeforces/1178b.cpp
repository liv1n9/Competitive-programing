#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 8;
char s[N], t[N];
int f[N][26];
int n;

int main() {
    scanf("%d", &n);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            f[i][j] = f[i - 1][j] + (int) (s[i] - 'a' == j);
        }
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        scanf("%s", t);
        vector<int> fre(26);
        for (int i = 0; t[i]; i++) {
            fre[t[i] - 'a']++;
        }
        int l = 1, r = n;
        int res;
        while (l <= r) {
            int m = (l + r) >> 1;
            bool ok = true;
            for (int i = 0; i < 26; i++) {
                if (f[m][i] < fre[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                res = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        printf("%d\n", res);
    }
}