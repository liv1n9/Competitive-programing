#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > res;
vector<int> p, pos;

void Swap(int x, int y) {
    res.push_back({x + 1, y + 1});
    swap(pos[p[x]], pos[p[y]]);
    swap(p[x], p[y]);
}

int main() {
    int n;
    scanf("%d", &n);
    p.resize(n);
    pos.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
        p[i]--;
        pos[p[i]] = i;
    }
    for (int i = 0; i < n / 2; i++) {
        int j = pos[i];
        if (j == i) continue;
        if (j < n / 2) {
            Swap(j, n - 1);
            Swap(i, n - 1);
        } else {
            Swap(0, j);
            if (i > 0) {
                Swap(i, n - 1);
                Swap(0, n - 1);
                Swap(i, n - 1);
                Swap(0, j);
            }
        }
    }
    for (int i = n / 2; i < n; i++) {
        int j = pos[i];
        if (j == i) continue;
        Swap(0, j);
        Swap(0, i);
        Swap(0, j);
    }
    cout << res.size() << endl;
    for (auto &i: res) {
        printf("%d %d\n", i.first, i.second);
    }
}