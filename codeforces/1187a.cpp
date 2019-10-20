#include <bits/stdc++.h>
using namespace std;

int main() {
    int test;
    cin >> test;
    while (test--) {
        long long n, s, t;
        cin >> n >> s >> t;
        long long v = s + t - n;
        s -= v;
        t -= v;
        cout << max(s + 1, t + 1) << endl;
    }
}