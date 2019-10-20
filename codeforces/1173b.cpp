#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int m = 0;
    vector<pair<int, int> > res;
    bool state = true;
    int x = 1, y = 1;
    for (int i = 1; i <= n; i++) {
        res.push_back({x, y});
        m = max(m, max(x, y));
        if (state == 1) {
            x += 1;
        } else {
            y += 1;
        }
        state ^= 1;
    }
    cout << m << endl;
    for (auto &i: res) {
        cout << i.first << " " << i.second << endl;
    }
}