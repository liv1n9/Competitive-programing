#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;

const ll INF = LLONG_MAX;
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

ll f[N][2];
char s[N];

void solve(int test_number) {
    int n;
    ll a, b;
    cin >> n >> a >> b;
    cin >> s + 1;
    for (int i = 0; i <= n; i++) {
        f[i][0] = f[i][1] = INF;
    }
    f[0][0] = b;
    for (int i = 1; i <= n; i++) {
        if (f[i - 1][0] < INF) {
            if (s[i] == '0') {
                f[i][1] = min(f[i][1], f[i - 1][0] + a * 2 + b * 2);
                f[i][0] = min(f[i][0], f[i - 1][0] + a + b);
            }
        }
        if (f[i - 1][1] < INF) {
            f[i][1] = min(f[i][1], f[i - 1][1] + a + b * 2);
            if (s[i] == '0') {
                f[i][0] = min(f[i][0], f[i - 1][1] + a * 2 + b);
            }
        }
    }
    cout << f[n][0] << endl;
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
    ios_base::sync_with_stdio(false);
    solve();
    #endif
    return 0;
}