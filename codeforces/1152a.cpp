#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int o1, o2, e1, e2;
    o1 = o2 = e1 = e2 = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        o1 += (x & 1);
    }
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        o2 += (x & 1);
    }
    e1 = n - o1;
    e2 = m - o2;
    cout << min(o2, e1) + min(o1, e2);
}