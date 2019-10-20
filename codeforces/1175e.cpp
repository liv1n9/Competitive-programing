#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 8;
const int X = 5e5 + 8;
const int INF = 1e9 + 8;

int t[X << 2], f[X << 2];
pair<int, int> p[N];
pair<int, int> q[N];
int n, t, m;

bool cmp(const pair<int, int> &p1, const pair<int, int> &p2) {
    return p1.second < p2.second;
}

void init(int k, int l, int r) {
    t[k] = f[k] = INF;
    if (l < r) {
        int m = (l + r) >> 1;
        init(k << 1, l, m);
        init(k << 1 ^ 1, m + 1, r);
    }
}

void lazy(int k, int l, int r) {
    if (f[k] != INF) {
        t[k] = min(t[k], f[k]);
        if (l < r) {
            f[k << 1] = min(f[k << 1], f[k]);
            f[k << 1 ^ 1] = min(f[k << 1 ^ 1], f[k]);
        }
        f[k] = INF;
    }
}

void update(int k, int l, int r, int x, int y, int v) {
    lazy(k, l, r);
    if (l > y || r < x) return;
    if (l >= x && r <= y) {
        f[k] = v;
        lazy(k, l, r);
        return;
    }
    int m = (l + r) >> 1;
    update(k << 1, l, m, x, y, v);
    update(k << 1 ^ 1, m + 1, r, x, y, v);
    t[k] = min(t[k << 1], t[k << 1 ^ 1]);
}

int get(int k, int l, int r, int x, int y) {
    lazy(k, l, r);
    if (l > y || r < x) return INF;
    if (l >= x && r <= y) return t[k];
    int m = (l + r) >> 1;
    return min(get(k << 1, l, m, x, y), get(k << 1 ^ 1, m + 1, r, x, y));
}

int main() {
    scanf("%d %d", &n, &t);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &p[i].first, &p[i].second);
    }
    sort(p + 1, p + 1 + n, cmp);
    m = p[n].second;
    init(1, 1, m);
    for (int i = 1; i <= n; i++) {
        int g = min(p[i].first, get(1, 1, m, p[i].first, p[i].second));
        update(1, 1, m, p[i].first, p[i].second, g);
    }
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        
    }
}