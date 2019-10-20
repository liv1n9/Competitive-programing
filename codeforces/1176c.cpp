#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a, b, c, d, e, f;
    a = b = c = d = e = f = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x == 4) {
            a++;
        }
        if (x == 8 && a > 0) {
            a--;
            b++;
        }
        if (x == 15 && b > 0) {
            b--;
            c++;
        }
        if (x == 16 && c > 0) {
            c--;
            d++;
        }
        if (x == 23 && d > 0) {
            d--;
            e++;
        }
        if (x == 42 && e > 0) {
            e--;
            f++;
        }
    }
    cout << n - f * 6;
}