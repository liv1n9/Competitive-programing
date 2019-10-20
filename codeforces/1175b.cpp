#include <bits/stdc++.h>
using namespace std;

int main() {
    int test;
    cin >> test;
    stack<long long> a, b;
    long long res = 0;
    long long lim = INT_MAX;
    lim = (lim + 1) * 2 - 1;
    while (test--) {
        string t;
        cin >> t;
        if (t == "for") {
            int n;
            cin >> n;
            a.push(n);
            b.push(0);
        } else if (t == "add") {
            if (!b.empty()) b.top()++;
            else res++;
            if (res > lim) {
                cout << "OVERFLOW!!!";
                return 0;
            }
        } else {
            long long x = a.top();
            long long y = b.top();
            a.pop();
            b.pop();
            if (!b.empty()) {
                b.top() += x * y;
                if (b.top() > lim) {
                    cout << "OVERFLOW!!!";
                    return 0;
                }
            } else {
                res += x * y;
                if (res > lim) {
                    cout << "OVERFLOW!!!";
                    return 0;
                }
            }
        }
    }
    cout << res;
}