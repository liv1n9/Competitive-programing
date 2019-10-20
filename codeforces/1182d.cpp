#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 8;
vector<int> G[N];
int d[N], pa[N], n;
int sz[N];
bool ok = true;

void dfs(int u) {
    for (int v: G[u]) {
        if (v != pa[u]) {
            pa[v] = u;
            d[v] = d[u] + 1;
            dfs(v);
        }
    }
}

void check(int u) {
    int pre = -1;
    for (int v: G[u]) {
        if (v != pa[u]) {
            pa[v] = u;
            check(v);
            if (pre == -1) {
                pre = sz[v];
            } else {
                if (sz[v] != pre) {
                    ok = false;
                }
            }
            sz[u]++;
        }
    }
}

int main() {
    scanf("%d", &n);
    if (n == 1) {
        cout << 1;
        return 0;
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1);
    int v = 0;
    for (int i = 1; i <= n; i++) {
        if (d[i] > d[v]) {
            v = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        pa[i] = 0;
        d[i] = 0;
    }
    d[v] = 0;
    dfs(v);
    int u = 0;
    for (int i = 1; i <= n; i++) {
        if (d[i] > d[u]) {
            u = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        pa[i] = 0;
    }
    check(v);
    if (ok) {
        cout << v;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        pa[i] = 0;
    }
    check(u);
    if (ok) {
        cout << u;
        return 0;
    }
    if (d[u] & 1 ^ 1) {
        int loop = d[u] / 2;
        while (loop--) {
            u = pa[u];
        }
        for (int i = 1; i <= n; i++) {
            pa[i] = 0;
        }
        check(u);
        cout << (ok ? u : -1);
    } else {
        cout << -1;
    }
}