#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 8;
pair<int, int> a[N];
int t[N << 4];
int n;

void update(int k, int l, int r, int x, int v) {
    if (l > x || r < x) return;
    if (l == x && r == x) {
        t[k] = v;
        return;
    }
    int m = (l + r) >> 1;
    update(k << 1, l, m, x, v);
    update(k << 1 ^ 1, m + 1, r, x, v);
    t[k] = max(t[k << 1], t[k << 1 ^ 1]);
}

int get(int k, int l, int r, int x, int y) {
    if (l > y || r < x) return 0;
    if (l >= x && r <= y) return t[k];
    int m = (l + r) >> 1;
    return max(get(k << 1, l, m, x, y), get(k << 1 ^ 1, m + 1, r, x, y));
}

bool cmp(const pair<int, int> &p1, const pair<int, int> &p2) {
    return p1.second < p2.second;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &a[i].first, &a[i].second);
    }
    sort(a + 1, a + 1 + n, &cmp);
    int res = 0;
    int m = n * 2;
    memset(t, 0, sizeof t);
    for (int i = 1; i <= n; i++) {
        if (a[i].first < a[i].second && a[i].second > 1) {
            int d = get(1, 1, m, 1, a[i].second - 1);
            res = max(res, d + 1);
            update(1, 1, m, a[i].first, d + 1);
        }
    }
    memset(t, 0, sizeof t);
    reverse(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        if (a[i].first > a[i].second && a[i].second < n) {
            int d = get(1, 1, m, a[i].second + 1, n);
            res = max(res, d + 1);
            update(1, 1, m, a[i].first, d + 1);
        }
    }
    cout << res;
}