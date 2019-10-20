#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i: a) {
        cin >> i;
    }
    sort(a.begin(), a.end());
    if (a[n - 1] < a[n - 2] + a[n - 3]) {
        cout << "YES\n";
        vector<int> r;
        for (int i = 0; i < n; i++) {
            if (i & 1 ^ 1) cout << a[i] << " ";
            else {
                r.push_back(a[i]);
            }
        } 
        reverse(r.begin(), r.end());
        for (int i: r) cout << i << " ";
    } else {
        cout << "NO";
    }
}