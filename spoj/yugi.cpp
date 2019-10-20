#include <bits/stdc++.h>
using namespace std;

const int N = 208;
const int M = 32768;
int a[N][N];
int root[N];
vector<pair<int, int> > e[M];
int n, k;
int res;
int c;

int getroot(int u) {
    return root[u] == 0 ? u : root[u] = getroot(root[u]);
}

void union_root(int u, int v) {
    int w = a[u][v];
    u = getroot(u);
    v = getroot(v);
    if (u != v) {
        c--;
        root[u] = v;
        if (c == k - 1) {
            res = w;
        }
    }
}

int main() {
    #ifdef TANNHA
    freopen(".inp", "r", stdin);
    freopen(".out", "w", stdout);
    #endif
    cin >> n >> k;
    c = n;
    int m = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            m = max(m, a[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            e[a[i][j]].push_back({i, j});
        }
    }
    for (int i = 1; i <= m; i++) {
        for (auto &p: e[i]) {
            union_root(p.first, p.second);
            if (c < k) {
                break;
            }
        }
    }
    cout << res;
}