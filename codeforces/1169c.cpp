#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &i: a) {
        cin >> i;
    }
    int l = 0, r = m - 1;
    int res;
    while (l <= r) {
        int g = (l + r) >> 1;
        int pre = 0;
        bool ok = true;
        for (int i: a) {
            int cur = -1;
            if (i > pre) {
                cur = i;
                if (g >= m - cur + pre) {
                    cur = pre;
                }
            } else {
                if (pre - i <= g) {
                    cur = pre;
                }
            }
            if (cur == -1) {
                ok = false;
                break;
            }
            pre = cur;
        }
        if (ok) {
            res = g;
            r = g - 1;
        } else {
            l = g + 1;
        }
    }
    cout << res << endl;
}