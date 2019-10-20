#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;

const double INF = 1e18;
const double EPS = 1e-8;
const int MOD = 1e9 + 7;
const int N = 1e6 + 8;

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

int n, m;
string s[N];

void solve(int test_number) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<vector<bool> > f(n, vector<bool>(m, false));
    vector<vector<ll> > l(n, vector<ll>(m, 0));
    vector<vector<ll> > r(n, vector<ll>(m, 0));
    f[0][0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            f[i][j] = (s[i][j] == '.');
            bool ok = false;
            if (i > 0) {
                ok |= f[i - 1][j];
            }
            if (j > 0) {
                ok |= f[i][j - 1];
            }
            f[i][j] = f[i][j] & ok;
        }
    }
    if (!f[n - 1][m - 1]) {
        cout << 0;
        return;
    }
    l[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i > 0) {
                l[i][j] = (l[i][j] + l[i - 1][j]) % MOD;
            }
            if (j > 0) {
                l[i][j] = (l[i][j] + l[i][j - 1]) % MOD;
            }
            if (s[i][j] == '#') {
                l[i][j] = 0;
            }
        }
    }
    r[n - 1][m - 1] = 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (i < n - 1) {
                r[i][j] = (r[i][j] + r[i + 1][j]) % MOD;
            }
            if (j < m - 1) {
                r[i][j] = (r[i][j] + r[i][j + 1]) % MOD;
            }
            if (s[i][j] == '#') {
                r[i][j] = 0;
            }
            if (!((i == 0 && j == 0) || (i == n - 1 && j == m - 1))) {
                if (s[i][j] == '.' && (l[i][j] * r[i][j]) % MOD == l[n - 1][m - 1]) {
                    cout << 1;
                    return;
                }
            }
        }
    }
    cout << 2;
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