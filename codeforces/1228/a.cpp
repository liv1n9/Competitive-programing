#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifdef TANNHA
    freopen(".inp", "r", stdin);
    freopen(".out", "w", stdout);
    #endif
    int l, r;
    cin >> l >> r;
    for (int i = l; i <= r; i++) {
        int j = i;
        set<int> x;
        int d = 0;
        while (j) {
            x.insert(j % 10);
            j /= 10;
            d++;
        }
        if (d == x.size()) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
}