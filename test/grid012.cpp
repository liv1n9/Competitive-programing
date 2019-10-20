#include <bits/stdc++.h>
using namespace std;

const int N = 1008;
char a[N][N];
int n, m;
vector<int> f[2][N];

vector<int> merge(const vector<int> &a, const vector<int> &b) {
    int i = 0;
    int j = 0;
    vector<int> c;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            c.push_back(a[i++]);
        } else {
            c.push_back(b[j]);
            if (b[j] == a[i]) {
                i++;
            }
            j++;
        }
    }
    
    while (i < a.size()) {
        c.push_back(a[i++]);
    }
    while (j < b.size()) {
        c.push_back(b[j++]);
    }
    return c;
}

int main() {
    freopen(".inp", "r", stdin);
    freopen(".out", "w", stdout);
    int test;
    cin >> test;
    while (test--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%s", a[i] + 1);
        }
        int curr = 0;
        f[1][1] = {0};
        for (int i = 1; i <= n; i++) {
            curr ^= 1;
            for (int j = 1; j <= m; j++) {
                if (i == 1 && j == 1) continue;
                f[curr][j] = vector<int>();
                if (i > 1) {
                    auto temp = f[curr ^ 1][j];
                    for (auto &x: temp) {
                        x += a[i][j] - 48;
                    }
                    f[curr][j] = merge(f[curr][j], temp);
                }
                if (j > 1) {
                    auto temp = f[curr][j - 1];
                    for (auto &x: temp) {
                        x += a[i][j] - 48;
                    }
                    f[curr][j] = merge(f[curr][j], temp);
                }
            }
        }
        for (int i: f[curr][m]) {
            printf("%d ", i);
        }
        cout << endl;
    }    
}