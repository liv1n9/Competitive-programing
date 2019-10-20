#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 8;
vector<int> G[N];
int hchild[N];
int last[N];
int pa[N], d[N], g[N];

int d_u(int u) {
    cout << "d " << u << endl;
    cin >> u;
    return u;
}

int s_u(int u) {
    cout << "s " << u << endl;
    cin >> u;
    return u;
}

void dfs(int u) {
    g[u] = 1;
    for (int v: G[u]) {
        if (v != pa[u]) {
            d[v] = d[u] + 1;
            pa[v] = u;
            dfs(v);
            g[u] += g[v];
            if (g[hchild[u]] < g[v]) {
                hchild[u] = v;
            }
        }
    }
}

void hld(int u) {
    last[u] = u;
    if (hchild[u] > 0) {
        hld(hchild[u]);
        last[u] = last[hchild[u]];
    }
    for (int v: G[u]) {
        if (v != pa[u] && v != hchild[u]) {
            hld(v);
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1);
    hld(1);
    int u = 1;
    int dist_x = d_u(u);
    while (true) {
        int dist_y = d_u(last[u]);
        dist_y = d[last[u]] - (dist_x + d[last[u]] - dist_y) / 2;
        u = last[u];
        while (dist_y--) {
            u = pa[u];
        }
        if (d[u] < dist_x) {
            u = s_u(u);
        } else {
            break;
        }
    }
    cout << "! " << u << endl;
}