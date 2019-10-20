#include <bits/stdc++.h>
using namespace std;

const int N = 4008;

set<int> G[N];
bool used[N];
int color[N];
int bin[N];
pair<int, int> d[N];
int k;
int res[N];

void dfs(int u) {
    used[u] = true;
    color[u] = k;
    d[k].first++;
    for (int v: G[u]) {
        if (!used[v]) {
            dfs(v);
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int test;
    cin >> test;
    for (int I = 1; I <= test; I++) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            G[i].clear();
            used[i] = false;
        }
        for (int i = 1; i <= m; i++) {
            int l, r;
            cin >> l >> r;
            while (l < r) {
                G[l].insert(r);
                G[r].insert(l);
                l++;
                r--;
            }
        }
        k = 0;
        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                k++;
                d[k].first = 0;
                d[k].second = k;
                dfs(i);
            }
        }
        sort(d + 1, d + 1 + k);
        for (int i = 1; i <= k; i++) {
            bin[d[i].second] = i & 1;
        }
        int zero, one;
        zero = one = 0;
        for (int i = 1; i <= n; i++) {
            if (used[i]) {
                res[i] = bin[color[i]];
                zero += (int) (bin[color[i]] == 0);
                one += (int) (bin[color[i]] == 1);
            }
        }
        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                if (zero > one) {
                    one++;
                    res[i] = 1;
                } else {
                    zero++;
                    res[i] = 0;
                }
            }
        }
        cout << "Case #" << I << ": ";
        for (int i = 1; i <= n; i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
}