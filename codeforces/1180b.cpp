#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    int prod = 1;
    for (int &i: a) {
        cin >> i;
        if (i >= 0) {
            i = -i - 1;
        }
        prod *= i > 0 ? 1 : -1;
    }
    if (prod < 0) {
        int m = INT_MAX;
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < m) {
                m = a[i];
                j = i;
            }
        }
        a[j] = -a[j] - 1;
    }
    for (auto i: a) {
        cout << i << " ";
    }
}