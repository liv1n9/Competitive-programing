#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;

const double INF = 1e18;
const double EPS = 1e-8;
const int MOD = 998244353;
const int N = 3e5 + 8;

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

ll fac[N];

ll calc(vector<pair<int, int> > &p) {
    vector<int> d;
    int cur;
    for (int i = 0; i < len(p); i++) {
        if (i == 0 || p[i].first != cur) {
            d.push_back(1);
            cur = p[i].first;
        } else {
            d.back()++;
        }   
    }
    ll res = 1;
    for (int i: d) {
        res = (res * fac[i]) % MOD;
    }
    return res;
}

void solve(int test_number) {
    int n;
    scanf("%d", &n);
    vector<pair<int, int> > p(n);
    for (auto &i: p) {
        scanf("%d %d", &i.first, &i.second);
    }
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = (fac[i - 1] * i) % MOD;
    }

    sort(p.begin(), p.end());
    pair<int, int> cur;
    vector<int> d;
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (i == 0 || p[i].first != cur.first || p[i].second != cur.second) {
            d.push_back(1);
            cur = p[i];
        } else {
            d.back()++;
        }
        if (i > 0 && p[i].second < p[i - 1].second) {
            ok = false;
            break;
        }
    }

    ll f0 = 0;
    if (ok) {
        f0 = 1;
        for (int i: d) {
            f0 = (f0 * fac[i]) % MOD;
        }
    }

    ll f1 = calc(p);
    for (auto &i: p) {
        swap(i.first, i.second);
    }
    sort(p.begin(), p.end());
    ll f2 = calc(p);
    debug(f0, f1, f2);
    ll res = (fac[n] - f2 - f1 + f0) % MOD;
    if (res < 0) res += MOD;
    cout << res;
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