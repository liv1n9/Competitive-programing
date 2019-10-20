#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 8;

int f[N][4];
vector<pair<int, int> > G[N];
int n;
long long res;

void dfs(int u, int p) {
    for (auto &e: G[u]) {
        if (e.first != p) {
            dfs(e.first, u);
        }
    }
    for (int loop = 1; loop <= 2; loop++) {
        for (int i = 0; i < 4; i++) {
            f[u][i] = 0;
        }
        reverse(G[u].begin(), G[u].end());
        for (auto &e: G[u]) {
            if (e.first == p) continue;
            int v = e.first;
            int c = e.second;
            vector<int> temp(4);
            if (c == 0) {
                temp[0] = f[v][0] + f[v][3];
                temp[1] = 0;
                temp[2] = 1 + f[v][2];
                temp[3] = 0;
            } else {
                temp[0] = 0;
                temp[1] = f[v][1] + f[v][2];
                temp[2] = 0;
                temp[3] = 1 + f[v][3];
            }
            res += (long long)temp[1] * f[u][3];
            res += (long long)temp[2] * (f[u][0] + f[u][2] + f[u][3]);
            res += (long long)temp[3] * f[u][3];
            for (int i = 0; i < 4; i++) {
                f[u][i] += temp[i];
            }
        }
    }
    res += f[u][0] + f[u][1] + f[u][2] * 2 + f[u][3] * 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        G[u].push_back({v, c});
        G[v].push_back({u, c});
    }
    dfs(2, 0);
    cout << res;
}