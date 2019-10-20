#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i + i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i & 1) {
                printf("%d %d\n%d %d\n", i, j, n - i + 1, m - j + 1);
            } else {
                printf("%d %d\n%d %d\n", i, m - j + 1, n - i + 1, j);
            }
        }
    }
    if (n & 1) {
        int i = (n + 1) / 2;
        int l = 1, r = m;
        for (int j = 1; j <= m; j++) {
            if (j & 1) {
                printf("%d %d\n", i, l++);
            } else {
                printf("%d %d\n", i, r--);
            }
        }
    }
}