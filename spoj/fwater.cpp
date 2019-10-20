#include <bits/stdc++.h>
using namespace std;
const int N = 308;

int w[N];
int root[N];
int mw[N];
vector<tuple<int, int, int> > e;

int getroot(int u) {
    return root[u] == 0 ? u : root[u] = getroot(root[u]);
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        mw[i] = w[i];
        sum += w[i];
    }
    int res = sum;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int p;
            cin >> p;
            if (i < j) {
                e.push_back(make_tuple(p, i, j));
            }
        }
    }
    sort(e.begin(), e.end());
    for (auto &p: e) {
        int c, u, v;
        tie(c, u, v) = p;
        u = getroot(u);
        v = getroot(v);
        if (u == v) {
            continue;
        }
        if (mw[u] < mw[v]) {
            swap(u, v);
        }
        if (c < mw[u]) {
            sum += c - mw[u];
            res = min(res, sum);
            root[v] = u;
            mw[u] = mw[v];
        }
    }
    cout << res;
}