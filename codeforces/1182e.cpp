#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll, ll, ll, ll> ti4;
const int MOD = 1e9 + 6;
const int MOD1 = 1e9 + 7;

ll n, f1, f2, f3, p;

struct matrix_x { 
    ti4 x[5][5];
};

struct matrix_y {
    ll x[5][5];
};

matrix_x mul(matrix_x a, matrix_y b) {
    matrix_x c;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            ll x, y, z, t;
            x = y = z = t = 0;
            for (int k = 0; k < 5; k++) {
                x += get<0>(a.x[i][k]) * b.x[k][j];
                y += get<1>(a.x[i][k]) * b.x[k][j];
                z += get<2>(a.x[i][k]) * b.x[k][j];
                t += get<3>(a.x[i][k]) * b.x[k][j];
            }
            c.x[i][j] = make_tuple(x % MOD, y % MOD, z % MOD, t % MOD);
        }
    }
    return c;
}

matrix_y mul(matrix_y a, matrix_y b) {
    matrix_y c;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            c.x[i][j] = 0;
            for (int k = 0; k < 5; k++) {
                c.x[i][j] = (c.x[i][j] + a.x[i][k] * b.x[k][j]) % MOD;
            }
        }
    }
    return c;
}

matrix_y powr(matrix_y a, ll x) {
    if (x == 1) return a;
    matrix_y d = powr(a, x >> 1);
    d = mul(d, d);
    if (x & 1) return mul(d, a);
    return d;
}

ll powr(ll a, ll x) {
    if (x == 0) return 1;
    ll d = powr(a, x >> 1);
    d = (d * d) % MOD1;
    if (x & 1) return (d * a) % MOD1;
    return d;
}

int main() {
    cin >> n >> f1 >> f2 >> f3 >> p;
    matrix_x a;
    matrix_y b;
    matrix_x c;
    a.x[0][0] = make_tuple(0, 0, 0, 1);
    a.x[0][1] = make_tuple(0, 0, 0, 4);
    a.x[0][2] = make_tuple(1, 0, 0, 0);
    a.x[0][3] = make_tuple(0, 1, 0, 0);
    a.x[0][4] = make_tuple(0, 0, 1, 0);
    b.x[0][0] = 1; b.x[1][0] = b.x[2][0] = b.x[3][0] = b.x[4][0] = 0;
    b.x[0][1] = b.x[1][1] = 1; b.x[2][1] = b.x[3][1] = b.x[4][1] = 0;
    b.x[0][2] = b.x[1][2] = b.x[2][2] = b.x[4][2] = 0; b.x[3][2] = 1;
    b.x[0][3] = b.x[1][3] = b.x[2][3] = b.x[3][3] = 0; b.x[4][3] = 1;
    b.x[0][4] = -6; b.x[1][4] = 2; b.x[2][4] = b.x[3][4] = b.x[4][4] = 1;
    c = mul(a, powr(b, n - 3));
    ll x, y, z, t;
    tie(x, y, z, t) = c.x[0][4];
    ll res = powr(f1, x);
    res = (res * powr(f2, y)) % MOD1;
    res = (res * powr(f3, z)) % MOD1;
    res = (res * powr(p, t)) % MOD1;
    if (res < 0) res += MOD1;
    cout << res;
}