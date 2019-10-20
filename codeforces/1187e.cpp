#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 8;

vector<int> G[N];
queue<int> q;
int pa[N];
int color[N];
int n;
long long res = 0;

void dfs(int u, int p) {
    bool leaf = true;
    pa[u] = p;
    for (int v: G[u]) {
        if (v != p) {
            leaf = false;
            dfs(v, u);
        }
    }
    if (leaf) {
        color[u] = 2;
        q.push(u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int s = 1;
    for (int i = 2; i <= n; i++) {
        if (G[i].size() > 1) {
            s = i;
            break;
        }
    }
    dfs(s, 0);
    int curr = n;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (color[u] == 2) {
            if (pa[u] > 0 && color[pa[u]] == 0) {
                color[pa[u]] = 1;
                q.push(pa[u]);
            }
            res += curr--;
        } else if (color[u] == 1) {
            
        }
    }
}