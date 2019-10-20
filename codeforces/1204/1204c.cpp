#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
 
const int INF = 1e6;
const double EPS = 1e-8;
const int MOD = 1e9 + 7;
const int N = 108;
 
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
 
int n;
int m;
int a[N][N];
int d[N][N];
 
void solve(int test_number) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        char s[n + 1];
        scanf("%s", s + 1);
        for (int j = 1; j <= n; j++) {
            a[i][j] = s[j] - '0';
        }
    }
    scanf("%d", &m);
    vector<int> p(m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 1) {
                d[i][j] = 1;
            } else {
                d[i][j] = INF;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
            }
        }
    }
    vector<int> res(1, p[0]);
    int cnt = 0;
    int cur = p[0];
    for (int i = 1; i < m; i++) {
        cnt++;
        if (d[cur][p[i]] != cnt || p[i] == res.back()) {
            res.push_back(p[i - 1]);
            cur = p[i - 1];
            cnt = 1;
        }
    }
    res.push_back(p[m - 1]);
    printf("%d\n", len(res));
    for (int i: res) {
        printf("%d ", i);
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