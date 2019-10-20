#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, x, b, y;
    cin >> n >> a >> x >> b >> y;
    do {
        a++;
        b--;
        if (a > n) a = 1;
        if (b == 0) b = n;
        if (a == b) {
            cout << "YES";
            return 0;
        }
    } while (a != x && b != y);
    cout << "NO";
}