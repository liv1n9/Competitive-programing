#include <bits/stdc++.h>
using namespace std;

const char ST = '*';

char s[508][508];
int x = -1, y;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] + 1;
    }
    for (int i = 2; i < n; i++) {
        for (int j = 2; j < m; j++) {
            if (s[i][j] == ST && s[i - 1][j] == ST && s[i + 1][j] == ST && s[i][j - 1] == ST && s[i][j + 1] == ST) {
                x = i;
                y = j;
            }
        }
    }
    if (x != -1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i != x && j != y && s[i][j] == ST) {
                    cout << "NO";
                    return 0;
                }
            }
        }
        cout << "YES";
    } else {
        cout << "NO";
    }
}