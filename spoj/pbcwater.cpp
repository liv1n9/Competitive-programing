#include <bits/stdc++.h>
using namespace std;
const int N = 1008;
const int M = 1e6 + 8;

int h[N][N];
pair<int, int> root[N][N];
vector<pair<int, int> > pos[M];
int d[N][N];
int label[N][N];
bool leak[N][N];
int n, m;

const int px[] = {0, 0, -1, 1};
const int py[] = {-1, 1, 0, 0};

long long res;

pair<int, int> getroot(int u, int v) {
    return make_pair(u, v) == root[u][v] ? root[u][v] : root[u][v] = getroot(root[u][v].first, root[u][v].second);
}

void union_root(int u, int v, int x, int y) {
    if (u == x && v == y) {
        return;
    }
    if (!leak[x][y]) {
        res += (label[u][v] - label[x][y]) * d[x][y];
    }
    root[x][y] = {u, v};
    d[u][v] += d[x][y];
    leak[u][v] |= leak[x][y];
}

int main() {
    #ifdef TANNHA
    freopen(".inp", "r", stdin);
    freopen(".out", "w", stdout);
    #endif

    scanf("%d %d", &n, &m);
    int k = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &h[i][j]);
            k = max(k, h[i][j]);
            pos[h[i][j]].push_back({i, j});
        }
    }
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            label[i][j] = h[i][j];
            root[i][j] = {i, j};
            d[i][j] = 1;
        }
    }
    for (int i = 0; i <= n + 1; i++) {
        leak[i][0] = leak[i][m + 1] = true;
    }
    for (int i = 0; i <= m + 1; i++) {
        leak[0][i] = leak[n + 1][i] = true;
    }
    for (int i = 1; i <= k; i++) {
        for (auto &p: pos[i]) {
            for (int j = 0; j < 4; j++) {
                int x = px[j] + p.first;
                int y = py[j] + p.second;
                auto r1 = getroot(p.first, p.second);
                auto r2 = getroot(x, y);
                if (label[r1.first][r1.second] >= label[r2.first][r2.second]) {
                    union_root(r1.first, r1.second, r2.first, r2.second);
                }
            }
        }
    }
    cout << res;
}