#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    vector<int> a(n);
    deque<int> dq;
    int large = 0;
    for (int &i: a) {
        cin >> i;
        large = max(large, i);
        dq.push_back(i);
    }
    vector<pair<int, int> > res(1);
    int lim = 0;
    while (dq.front() != large) {
        int x = dq.front();
        dq.pop_front();
        int y = dq.front();
        res.push_back({x, y});
        if (x < y) {
            swap(x, y);
        }
        dq.pop_front();
        dq.push_front(x);
        dq.push_back(y);
        lim++;
    }
    for (int i = 1; i < n; i++) {
        int x = dq.front();
        dq.pop_front();
        int y = dq.front();
        res.push_back({x, y});
        dq.pop_front();
        dq.push_front(x);
        dq.push_back(y);
    }
    while (q--) {
        long long p;
        scanf("%lld", &p);
        if (p > lim) {
            p = (p - lim - 1) % (n - 1) + lim + 1;
        }
        printf("%d %d\n", res[p].first, res[p].second);
    }
}