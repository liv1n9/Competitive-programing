#include <bits/stdc++.h>
using namespace std;

const int N = 58;
const int px[] = {-1, 1, 0, 0};
const int py[] = {0, 0, -1, 1};

char s[N][N];
int n;

int sum(int i, int j) {
    int res = 0;
    for (int k = 0; k < 4; k++) {
        int x = i + px[k];
        int y = j + py[k];
        res += (int)(s[x][y] == '.');
    }
    return res + (int)(s[i][j] == '.');
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] + 1;
    }
    for (int i = 2; i < n; i++) {
        for (int j = 2; j < n; j++) {
            if (sum(i, j) == 5) {
                for (int k = 0; k < 4; k++) {
                    int x = i + px[k];
                    int y = j + py[k];
                    s[x][y] = '#';
                }
                s[i][j] = '#';
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i][j] == '.') {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}