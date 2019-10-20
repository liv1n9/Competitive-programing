#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;

const double INF = 1e18;
const double EPS = 1e-8;
const int MOD = 1e9 + 7;
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

int a, b;
bool f[N], g[N];
bool tf[N << 2], tg[N << 2];
char s[N];
int n;

void build(bool t[], int k, int l, int r) {
    if (l == r) {
        t[k] = false;
        return;
    }
    int m = (l + r) >> 1;
    build(t, k << 1, l, m);
    build(t, k << 1 ^ 1, m + 1, r);
    t[k] = false;
}

void update(bool t[], int k, int l, int r, int i, bool v) {
    if (l > i || r < i) {
        return;
    }
    if (l == i && r == i) {
        t[k] = v;
        return;
    }
    int m = (l + r) >> 1;
    update(t, k << 1, l, m, i, v);
    update(t, k << 1 ^ 1, m + 1, r, i, v);
    t[k] = t[k << 1] | t[k << 1 ^ 1];
}

bool get(bool t[], int k, int l, int r, int x, int y) {
    if (l > y || r < x) {
        return false;
    }
    if (l >= x && r <= y) {
        return t[k];
    }
    int m = (l + r) >> 1;
    return get(t, k << 1, l, m, x, y) | get(t, k << 1 ^ 1, m + 1, r, x, y);
}

void solve(int test_number) {
    scanf("%d %d", &a, &b);
    scanf("%s", s + 1);
    while (s[n + 1]) n++;
    build(tf, 1, 1, n);
    build(tg, 1, 1, n);
    for (int i = 1; i <= n; i++) {
        if (i < a) {
            f[i] = false;
        } else {
            if (i - a <= b * 2 - 2) {
                f[i] = true;
            } else {
                f[i] = get(tf, 1, 1, n, 1, i - a - b + 1);
            }
        }
        update(tf, 1, 1, n, i, f[i]);
        if (i < b) {
            g[i] = false;
        } else {
            if (i - b <= a * 2 - 2) {
                g[i] = true;
            } else {
                g[i] = get(tg, 1, 1, n, 1, i - b - a + 1);
            }
        }
        update(tg, 1, 1, n, i, g[i]);
    }
    vector<int> d;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '.') {
            if (i == 1 || s[i] != s[i - 1]) {
                d.push_back(1);
            } else {
                d.back()++;
            }
        }
    }
    int x, y, z, t;
    x = y = z = t = 0;
    for (int i : d) {
        debug(i, f[i], g[i]);
        if (f[i]) {
            x++;
            if (!g[i]) {
                y++;
            }
        } else {
            z++;
            if (!g[i]) {
                t++;
            }
        }
    }
    int m = d.size() / 2;
    debug(x, y, z, t, m);
    if (x >= m) {
        if (y >= x - m && z == t) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else {
        cout << "NO\n";
    }
}

void initialize() {}

void initialize(int test_number) {}

void solve() {
    initialize();
    int test = 1; if (true) cin >> test;
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
    solve();
    #endif
    return 0;
}