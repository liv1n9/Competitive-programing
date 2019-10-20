#include <bits/stdc++.h>
using namespace std;

const int N = 5e5;

int root[N], d[N];

int getroot(int u) {
    return root[u] == -1 ? u : root[u] = getroot(root[u]);
}

void Union(int u, int v) {
    u = getroot(u);
    v = getroot(v);
    if (u == v) return;
    if (d[u] > d[v]) swap(u, v);
    root[u] = v;
    d[v] += d[u];
}

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int> > g(m);
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        while (k--) {
            int x;
            cin >> x;
            x--;
            g[i].push_back(x);
        }
    }
    for (int i = 0; i < n; i++) {
        root[i] = -1;
        d[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 1; j < g[i].size(); j++) {
            Union(g[i][j - 1], g[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << d[getroot(i)] << " ";
    }
}