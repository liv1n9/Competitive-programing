#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, h, m;
    cin >> n >> h >> m;
    vector<int> res(n, h);
    while (m--) {
        int l, r, x;
        cin >> l >> r >> x;
        l--;
        r--;
        for (int i = l; i <= r; i++) {
            res[i] = min(res[i], x);
        }
    }    
    int ans = 0;
    for (int i: res) {
        ans += i * i;
    }
    cout << ans;
}