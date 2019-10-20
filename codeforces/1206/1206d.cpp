#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
 
const double INF = 1e18;
const double EPS = 1e-8;
const int MOD = 1e9 + 7;
const int N = 1e5 + 8;
 
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
 
vector<int> f[64];
vector<int> g[N];
long long a[N];
int q[N];
int d[N];
int pa[N];
int n;
 
int bfs(int s) {
    int l, r;
    l = r = 0;
    q[0] = s;
    for (int i = 1; i <= n; i++) {
        d[i] = 0;
    }
    d[s] = 1;
    pa[s] = 0;
    int res = n + 1;
    while (l <= r) {
        int u = q[l++];
        for (int v: g[u]) {
            if (v != pa[u]) {
                if (d[v] == 0) {
                    q[++r] = v;
                    d[v] = d[u] + 1;
                    pa[v] = u;
                } else {
                    return d[u] + d[v] - 1;
                }
            }
        }
    }
    return res;
}
 
void solve(int test_number) {
    scanf("%d", &n);
    int m = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] > 0) {
            a[++m] = a[i];
        }
        if (a[i] > 0) {
            for (int j = 0; j < 64; j++) {
                if (bit(a[i], j) == 1) {
                    f[j].push_back(i);
                }
            }
        }
    }
    for (int i = 0; i < 64; i++) {
        if (f[i].size() >= 3) {
            cout << 3;
            return;
        }
    }
    n = m;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (i != j && (a[i] & a[j]) != 0) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    int res = n + 1;
    for (int i = 1; i <= n; i++) {
        res = min(res, bfs(i));
    }
    if (res == n + 1) {
        res = -1;
    }
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
    solve();
    #endif
    return 0;
}