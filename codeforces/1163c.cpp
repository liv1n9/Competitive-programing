#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct point {
    ll x, y;
};

tuple<ll, ll, ll> line(point p1, point p2) {
    ll a, b, c;
    a = p1.y - p2.y;
    b = p2.x - p1.x;
    c = -(a * p1.x + b * p1.y);
    ll d = __gcd(a, __gcd(b, c));
    a /= d;
    b /= d;
    c /= d;
    if (a < 0) {
        a *= -1;
        b *= -1;
        c *= -1;
    }
    return make_tuple(a, b, c);
}

int main() {
    int n;
    cin >> n;
    vector<point> p(n);
    for (point &i: p) {
        cin >> i.x >> i.y;
    }
    set<tuple<ll, ll, ll> > lines;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            tuple<ll, ll, ll> temp = line(p[i], p[j]);
            lines.insert(temp);
            ll a = get<0>(temp);
            ll b = get<1>(temp);
            ll c = get<2>(temp);
        }
    }
    int m = lines.size();
    ll res = 0;
    map<pair<int, int>, int> palas;
    for (auto &i: lines) {
        ll a = get<0>(i);
        ll b = get<1>(i);
        palas[{a, b}]++;
    }
    for (auto &i: lines) {
        ll a = get<0>(i);
        ll b = get<1>(i);
        ll c = get<2>(i);
        res += m - palas[{a, b}];
    }
    cout << res / 2;
}