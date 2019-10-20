#include <bits/stdc++.h>
using namespace std;

long long calc(long long n, long long k) {
    if (n <= 1) return n;
    if (n % k == 0) return 1 + calc(n / k, k);
    return n % k + calc(n - n % k, k);
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        long long n, k;
        cin >> n >> k;
        cout << calc(n, k) << endl;
    }
}