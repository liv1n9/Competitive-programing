#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    long long x = min(a, b);
    long long res = (x + c) * 2;
    a -= x;
    b -= x;
    if (a + b > 0) {
        res++;
    }
    cout << res;
}