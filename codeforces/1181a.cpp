#include <bits/stdc++.h>
using namespace std;

long long res = LLONG_MAX;
long long x, y, z, t;
void calc(long long a) {
    long long v = (x - a) / z + (y + a) / z;
    if (v > t) {
        res = a;
        t = v;
    } else if (v == t) {
        res = min(res, abs(a));
    }
}

int main() {
    cin >> x >> y >> z;
    t = (x + y) / z;
    long long a = ((z - y) % z + z) % z;
    calc(0);
    calc(x % z);
    calc(-(y % z));
    if (x >= a) {
        calc(a);
    }
    a = ((z - x) % z + z) % z;
    if (y >= a) {
        calc(-a);
    }
    cout << t << " " << res;
}