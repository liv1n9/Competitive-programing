#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;

const double INF = 1e18;
const double EPS = 1e-8;
const int MOD = 1e9 + 7;
const int N = 2e5 + 8;

#define len(x) (int)(x).size()
#define lowest(x) (*(x).begin())
#define highest(x) (*(x).rbegin())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define contain(a, x...) (a.find(x) != a.end())
#define pqmax(x...) priority_queue<x>
#define pqmin(x...) priority_queue<x, vector<x>, greater<x> >
mt19937 mt_gen(chrono::high_resolution_clock::now().time_since_epoch().count());

inline int gen() {return abs((int) mt_gen());}
inline int gen(int n) {return gen() % n;}
inline int bit(ll x, int i) {return (x >> i) & 1;}
inline int bitcount(ll x) {return __builtin_popcountll(x);}
inline ll lcm(ll x, ll y) {return x / __gcd(x, y) * y;}
inline ll toggle(ll x, int i, int v = 1) {return x ^ ((ll) v << i);}
inline ll powr(ll a, ll x, ll m = MOD) {ll r = 1; for (; x; x >>= 1) {if (x & 1) r = r * a % m; a = a * a % m;} return r;}
template<typename T, typename... V> inline void tomin(T &t, V... v) {t = min({t, v...});}
template<typename T, typename... V> inline void tomax(T &t, V... v) {t = max({t, v...});}

string to_string(char x) {return (string) "\'" + x + "\'";}
string to_string(const string &x) {return '\"' + x + '\"';}
string to_string(const char *x) {return to_string((string) x);}
string to_string(bool x) {return x ? "true" : "false";}
template<typename T, typename V> string to_string(const pair<T, V> &x)
{return '(' + to_string(x.first) + ',' + to_string(x.second) + ')';}
template<typename T> string to_string(const T &x)
{int f = 0; string r; for (auto &i: x) r += (f++ ? "," : "") + to_string(i); return '{' + r + '}';}

void _print() {cerr << "]\n";}
template <typename T, typename... V> void _print(T t, V... v)
{cerr << to_string(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef TANNHA
#define debug(...)
#else
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#endif

ll t[N >> 4], t1[N >> 4], f[N >> 4];
int n;

void lazy(int k, int l, int r) {
    if (f[k] > 0) {
        t[k] += f[k];
        t1[k] += f[k] * (r - l + 1);
        if (l < r) {
            f[k << 1] += f[k];
            f[k << 1 ^ 1] += f[k];
        }
        f[k] = 0;
    }
}

void update(int k, int l, int r, int x, int y, ll v) {
    lazy(k, l, r);
    if (l > y || r < x) return;
    if (l >= x && r <= y) {
        f[k] = v;
        lazy(k, l, r);
        return;
    }
    int m = (l + r) >> 1;
    update(k << 1, l, m, x, y, v);
    update(k << 1 ^ 1, m + 1, r, x, y, v);
    t[k] = max(t[k << 1], t[k << 1 ^ 1]);
    t1[k] = t1[k << 1] + t1[k << 1 ^ 1];
}

ll get1(int k, int l, int r, int x, int y) {
    lazy(k, l, r);
    if (l > y || r < x) return 0;
    if (l >= x && r <= y) {
        return t[k];
    }
    int m = (l + r) >> 1;
    return max(get1(k << 1, l, m, x, y), get1(k << 1 ^ 1, m + 1, r, x, y));
}
ll get2(int k, int l, int r, int x, int y) {
    lazy(k, l, r);
    if (l > y || r < x) return 0;
    if (l >= x && r <= y) {
        return t1[k];
    }
    int m = (l + r) >> 1;
    return (get2(k << 1, l, m, x, y) + get2(k << 1 ^ 1, m + 1, r, x, y));
}

ll g(ll x) {
    ll res = sqrt(x * 2);
    if (res * (res + 1) / 2 <= x) res++;
    if (res * (res - 1) / 2 > x) res--;
    return res;
}

void solve(int test_number) {
    cin >> n;
    vector<ll> s(n);
    for (auto &i: s) {
        cin >> i;
    }
    vector<int> res;
    int temp = g(s.back());
    res.push_back(temp);
    update(1, 1, n, temp, temp, s.back());
    for (int i = n - 2; i >= 0; i--) {
        int l = 1, r = n;
        int j = 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            int p = get1(1, 1, n, m, n);
            if (p >= s[i]) {
                j = p;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        int x = g(s[i] + get2(1, 1, n, 1, j - 1));
        res.push_back(x);
        update(1, 1, n, x + 1, n, -x);
    }
    reverse(all(res));
    for (int i: res) {
        cout << i << " ";
    }

}

void initialize() {}

void initialize(int test_number) {}

void solve() {
    initialize();
    int test = 1; if (false) cin >> test;
    for (int i = 1; i <= test; i++) {
        initialize(i);
        solve(i);
    }
}

int main(int argc, char *argv[]) {
    #ifdef TANNHA
    auto start = chrono::steady_clock::now();
    freopen(".inp", "r", stdin); freopen(".out", "w", stdout); solve();
    fprintf(stderr, "\n[%.3f s]\n", chrono::duration<double>(chrono::steady_clock::now() - start).count());
    #else
    ios_base::sync_with_stdio(false);
    solve();
    #endif
    return 0;
}