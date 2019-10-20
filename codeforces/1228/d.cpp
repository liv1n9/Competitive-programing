#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 8;
int color[N];
int p[N];
bool changed[N];
vector<int> G[N];
bool ok = true;

void bfs(int u) {
    color[u] = 1;
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int v: G[u]) {
            if (v != p[u]) {
                if (color[v] == 0) {
                    for (int c = 1; c <= 3; c++) {
                        if (c != color[u]) {
                            color[v] = c;
                            break;
                        }
                    }
                    q.push(v);
                    p[v] = u;
                } else if (!changed[v]) {
                    for (int c = 1; c <= 3; c++) {
                        if (c != color[u]) {
                            color[v] = c;
                            break;
                        }
                    }
                    changed[v] = true;
                } else {
                    ok = false;
                    return;
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            bfs(i);
            if (!ok) {
                cout << "-1";
                return 0;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << color[i] << " ";
    }
}