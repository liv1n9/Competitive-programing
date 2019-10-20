#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 8;
int sz[N];
bool trv[N];
ll w[N];
vector<int> G[N];
int n;
ll res = 0;

void dfs(int u, int p, int &m) {
    m++;
    sz[u] = 1;
    for (int v: G[u]) {
        if (!trv[v] && v != p) {
            dfs(v, u, m);
            sz[u] += sz[v];
        }
    }
}

int centroid(int u, int p, int m) {
    for (int v: G[u]) {
        if (!trv[v] && v != p && sz[v] > m / 2) {
            return centroid(v, p, m);
        }
    }
    return u;
}

int centroid(int u) {
    int m = 0;
    dfs(u, 0, m);
    return centroid(u, 0, m);
}

void travel(int u, int p, ll g) {
    res += g;
    for (int v: G[u]) {
        if (!trv[v] && v != p) {
            travel(v, u, __gcd(g, w[u]));
        }
    }
}

void decompose(int u) {
    u = centroid(u);
    trv[u] = true;
    travel(u, 0, w[u]);
    for (int v: G[u]) {
        if (!trv[v]) {
            decompose(v);
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &w[i]);
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    decompose(1);
    cout << res;
}