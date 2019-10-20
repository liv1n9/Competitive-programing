#include <bits/stdc++.h>
using namespace std;

bool used[1000];
int res;
int a, b;

void dfs(int u, int m) {
    used[u] = true;
    res++;
    if (u + a <= m && !used[u + a]) {
        dfs(u + a, m);
    }
    if (u >= b && !used[u - b]) {
        dfs(u - b, m);
    }
}

int main() {
    int n;
    cin >> n >> a >> b;
    for (int m = 0; m <= n; m++) {
        memset(used, false, sizeof used);
        res = 0;
        dfs(0, m);
        cout << m << " " << res << endl;
    }
}