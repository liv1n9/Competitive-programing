#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> res(1, 1);
    for (int i = 1; i <= n / 2; i++) {
        res.push_back(i);
    }
    for (int i = (n - 1) / 2; i >= 0; i--) {
        res.push_back(i);
    }
    cout << res[m];
}