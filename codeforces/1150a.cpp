#include <bits/stdc++.h>
using namespace std;

const int N = 1008;
int f[N];

int main() {
    int n, m, r;
    cin >> n >> m >> r;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    for (int i = 1; i <= r; i++) {
        for (int j: a) {
            if (j <= i) {
                f[i] = max(f[i], f[i - j] + 1);
            }
        }
    }
    vector<int> b(m);
    for (int &i: b) cin >> i;
    int q = *max_element(b.begin(), b.end());
    int res = 0;
    for (int i = 0; i <= r; i++) {
        res = max(res, r - i + f[i] * q);
    }
    cout << res;
}