#include <bits/stdc++.h>
using namespace std;

int query_simple(int l, int r) {
    cout << "1 " <<  r - l + 1 << " 1";
    for (int i = l; i <= r; i++) {
        cout << " " << i;
    }
    cout << endl;
    int res; 
    cin >> res;
    return res;
}

int main() {
    srand(time(NULL));
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        int l = 2, r = n;
        int u;
        int first = query_simple(2, n);
        while (l < r) {
            int m = (l + r) >> 1;
            int t = query_simple(l, m);
            if (t == first) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        cout << 1 << " " << n - 1 << " " << l;
        for (int i = 1; i <= n; i++) {
            if (i != l) cout << " " << i;
        }
        cout << endl;
        int res;
        cin >> res;
        cout << "-1 " << res << endl;
    }
}