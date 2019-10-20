#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main() {
    int n;
    cin >> n;
    vector<ull> f(n + 1);
    f[0] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] += f[i - 2] * 2;
    }
    cout << f[n];
}