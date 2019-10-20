#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 8;

int a[N];
bool has[N];
int add[N];
int n, k;

int adj(int i) {
    return 1 + (int)(i > 1) + (int)(i < n);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
    }
    set<int> s;
    for (int i = k; i >= 1; i--) {
        has[a[i]] = true;
        add[a[i]] = 0;
        if (a[i] < n) add[a[i]] += (int)(s.find(a[i] + 1) == s.end());
        if (a[i] > 1) add[a[i]] += (int)(s.find(a[i] - 1) == s.end());
        s.insert(a[i]);
    }
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        if (!has[i]) {
            res += adj(i);
        } else {
            res += add[i];
        }
    }
    cout << res;
}