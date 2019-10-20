#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> powr(51);

string calc(ll a, ll b, ll m) {
    if (a == b) {
        return "1" + to_string(a);
    }
    for (int k = 1; k < 50; k++) {
        if (a > b / powr[k - 1]) break;
        ll rest = b - a * powr[k - 1];
        ll large = 0;
        for (int i = k - 2; k >= 0; k--) {
            large += powr[i];
        }
        if (large < rest) {
            bool ok = true;
            ll cur = 1;
            vector<ll> temp;
            for (int i = 1; i <= k; i++) {
                ll pos = min(m, (rest - large) / cur);
                if (pos == 0) {
                    ok = false;
                    break;
                }
                rest -= pos;
                if (i > 1) cur *= 2;
                temp.push_back(pos);
            }
            if (ok) {
                string res = to_string(a);
                reverse(temp.begin(), temp.end());
                ll sum = 0;
                for (ll i: temp) {
                    a += i;
                    sum += a;
                    res += " " + to_string(sum);
                }
                return res;
            }
        }
    }
    return "-1";
}

int main() {
    powr[0] = 1;
    for (int i = 1; i <= 50; i++) {
        powr[i] = powr[i - 1] * 2;
    }
    int q;
    cin >> q;
    while (q--) {
        ll a, b, m;
        cin >> a >> b >> m;
        cout << calc(a, b, m) << endl;
    }
}