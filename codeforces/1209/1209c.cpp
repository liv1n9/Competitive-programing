#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 8;
vector<int> G[N];
int res, n, k;
bool used[N];

void dfs(int u) {
    used[u] = true;
    for (int v: G[u]) {
        if (!used[v]) {
            dfs(v);
            res++;
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }
    cout << k - res;
}