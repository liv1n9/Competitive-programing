#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 8;

int root[N];
vector<tuple<int, int, int> > e;
int n, p;

int getroot(int u) {
    return root[u] == 0 ? u : root[u] = getroot(root[u]);
}

int main() {
    scanf("%d %d", &n, &p);
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int c;
        scanf("%d", &c);
        res += c * 2;
    }
    for (int i = 1; i <= p; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e.push_back(make_tuple(w, u, v));
    }
    sort(e.begin(), e.end());
    for (auto &i: e) {
        int w, u, v;
        tie(w, u, v) = i;
        u = getroot(u);
        v = getroot(v);
        if (u != v) {
            root[u] = v;
            res += w;
        }
    }
    cout << res;
}