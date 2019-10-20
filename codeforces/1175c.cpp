#include <bits/stdc++.h>
using namespace std;

int main() {
    int test;
    scanf("%d", &test);
    while (test--) {
        int n, k;
        scanf("%d %d", &n, &k);
        vector<int> a(n);
        for (int &i: a) {
            scanf("%d", &i);
        }
        int res = INT_MAX;
        int x;
        for (int i = k; i < n; i++) {
            if (res > (a[i] - a[i - k])) {
                res = a[i] - a[i - k];
                x = (a[i] + a[i - k]) / 2;
            }
        }
        cout << x << endl;
    }
}