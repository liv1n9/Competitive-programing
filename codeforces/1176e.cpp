#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 8;

vector<int> G[N];
int n, m;
int odd;
bool used[N], even[N];

void bfs(int u, bool is_even) {
    queue<int> q;
    q.push(u);
    even[u] = is_even;
    used[u] = true;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int v: G[u]) {
            if (!used[v]) {
                q.push(v);
                used[v] = true;
                even[v] = !even[u];
                odd += !even[v];
            }
        }
    }    
}

int main() {
    int test;
    scanf("%d", &test);
    while (test--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            G[i].clear();
            used[i] = false;
            even[i] = false;
        }
        for (int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        odd = 0;
        bfs(1, true);
        vector<int> res;
        if (odd <= n / 2) {
            for (int i = 1; i <= n; i++) {
                if (!even[i]) {
                    res.push_back(i);
                }
            }
        } else {
            for (int i = 1; i <= n; i++) {
                if (even[i]) {
                    res.push_back(i);
                }
            }
        }
        printf("%d\n", res.size());
        for (int i: res) {
            printf("%d ", i);
        }
        printf("\n");
    }
}