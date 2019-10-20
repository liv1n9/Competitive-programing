#include <bits/stdc++.h>
using namespace std;

const int N = 1008;
char a[N][N];
int n, m;
vector<int> f[N][N];

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
    freopen("grid012.inp", "r", stdin);
    freopen("grid012.out", "w", stdout);
    int test;
    cin >> test;
    while (test--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> a[i] + 1;
        }
        f[1][1] = {0};
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i == 1 && j == 1) continue;
                f[i][j] = vector<int>();
                if (i > 1) {
                    auto temp = f[i - 1][j];
                    for (auto &x: temp) {
                        x += a[i][j] - 48;
                    }
                    f[i][j] = merge(f[i][j], temp);
                }
                if (j > 1) {
                    auto temp = f[i][j - 1];
                    for (auto &x: temp) {
                        x += a[i][j] - 48;
                    }
                    f[i][j] = merge(f[i][j], temp);
                }
            }
        }
        for (int i: f[n][m]) {
            cout << i << " ";
        }
        cout << endl;
    }    
}