#include <bits/stdc++.h>
using namespace std;
 
const int N = 5008;
 
vector<pair<int, int> > G[N];
int low[N], num[N];
int color[N];
bool ins[N];
int cnt = 0;
int n, m;
stack<int> s;
int comp = 0;
int res[N];
int z = 1;
 
void dfs(int u) {
    low[u] = num[u] = ++cnt;
    s.push(u);
    ins[u] = true;
    for (auto &e: G[u]) {
        int v = e.first;
        if (num[v] == 0) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (ins[v]) {
            low[u] = min(low[u], num[v]);
        }
    }
    if (low[u] == num[u]) {
        comp++;
        int v;
        do {
            v = s.top();
            s.pop();
            ins[v] = false;
            color[v] = comp;
        } while (v != u);
    }
}

void tfs(int u, int c) {
    ins[u] = true;
    for (auto &e: G[u]) {
        int v = e.first;
        if (color[u] == color[v]) {
            res[e.second] = c;
        } else {
            res[e.second] = 1;
        }
        z = max(z, res[e.second]);
        if (!ins[v] && color[v] == color[u]) {
            tfs(v, 3 - res[e.second]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back({v, i});
    }
    for (int i = 1; i <= n; i++) {
        if (num[i] == 0) {
            dfs(i);
        }
    }
    memset(ins, false, sizeof ins);
    for (int i = 1; i <= n; i++) {
        if (!ins[i]) {
            tfs(i, 1);
        }
    }
    cout << z << "\n";
    for (int i = 1; i <= m; i++) {
        cout << res[i] << " ";
    }
}