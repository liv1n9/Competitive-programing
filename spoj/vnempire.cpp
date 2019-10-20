#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 8;

vector<tuple<ll, int, int > > e;
int root[N];
ll res;

int getroot(int u) {
    return root[u] == 0 ? u : root[u] = getroot(root[u]);
}

void union_root(int u, int v, ll w) {
    u = getroot(u);
    v = getroot(v);
    if (u != v) {
        res += w;
        root[u] = v;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<ll, int> > a, b, c;
    for (int i = 1; i <= n; i++) {
        ll x, y, z;
        cin >> x >> y >> z;
        a.push_back({x, i});
        b.push_back({y, i});
        c.push_back({z, i});
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    for (int i = 1; i < n; i++) {
        e.push_back(make_tuple(a[i].first - a[i - 1].first, a[i - 1].second, a[i].second));
        e.push_back(make_tuple(b[i].first - b[i - 1].first, b[i - 1].second, b[i].second));
        e.push_back(make_tuple(c[i].first - c[i - 1].first, c[i - 1].second, c[i].second));
    }
    sort(e.begin(), e.end());
    for (auto &i: e) {
        ll w;
        int u, v;
        tie(w, u, v) = i;
        union_root(u, v, w);
    }
    cout << res;
}