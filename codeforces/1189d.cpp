#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> f;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        f[a[i]]++;
        if (f[a[i]] > 2) {
            cout << "cslnb";
            return 0;
        }
    }
    sort(a.begin(), a.end());
    long long move = 0;
    int l = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= l) {
            move += a[i] - l;
            l++;
        }
    }
    cerr << move << endl;
    if (move & 1) {
        cout << "sjfnb";
    } else {
        cout << "cslnb";
    }
}