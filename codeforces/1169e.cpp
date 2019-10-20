#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 8;

int d[N];
vector<int> b[20];
bool used[20];
set<int> par[N];
int cnt;
int m;
bool ok;

void dfs(int u) {
    used[u] = false;
    
}

int main() {
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        for (int j = 0; (1 << j) <= d[i]; j++) {
            m = max(m, j);
            if ((d[i] >> j) & 1) {
                b[j].push_back(i);
            }
        }
    }
    while (q--) {
        int u, v;
        cin >> u >> v;
        ok = false;
        memset(used, 0, sizeof used);
        for (int i = 0; i <= m; i++) {
            if ((d[u] >> i) & 1 && !used[i]) {
                dfs(i);
            }
        }
    }
}