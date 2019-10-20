#include <bits/stdc++.h>
using namespace std;

const int N = 18;
const int M = 28;

vector<int> G[N];
pair<int, int> e[M];
int c[N];
int n, m;
int res;
int temp;
set<pair<int, int> > dom;
int cnt = 0;

void update() {
    dom.clear();
    temp = 0;
    for (int i = 1; i <= m; i++) {
        int u, v;
        u = e[i].first;
        v = e[i].second;
        if (c[u] > c[v]) {
            swap(u, v);
        }
        temp += (int) dom.insert({c[u], c[v]}).second;
    }
    res = max(res, temp);
}

void _try(int i) {
    for (int j = 1; j <= 6; j++) {
        c[i] = j;
        if (i < n) {
            _try(i + 1);
        } else {
            update();
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        e[i] = make_pair(u, v);
    }
    _try(1);
    cout << res;
}