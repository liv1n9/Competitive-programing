#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;

#define INF 1e18
#define EPS 1e-8
#define MOD 1e9 + 7
#define N 2008

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
template<typename T, typename V>
string to_string(const pair<T, V> &x) {return '{' + to_string(x.first) + ',' + to_string(x.second) + '}';}
template<typename T>
string to_string(const T &x) {int f = 0; string r = "{"; for (auto &i: x) r += (f++ ? "," : "") + to_string(i); return r + "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {cerr << to_string(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifdef TANNHA
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(...)
#endif

int ok_row[N], ok_col[N];
int up_row[N][N], up_col[N][N];
char s[N][N];
int t[N][N];
int n, k;
int res;

int get(int x1, int y1, int x2, int y2) {
    if (x1 > x2 || y1 > y2) return 0;
    return t[x2][y2] - t[x1 - 1][y2] - t[x2][y1 - 1] + t[x1 - 1][y1 - 1];    
}

void solve(int test_number) {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            t[i][j] = t[i - 1][j] + t[i][j - 1] - t[i - 1][j - 1] + (int)(s[i][j] == 'B');
        }
    }
    for (int i = 1; i <= n; i++) {
        ok_row[i] = ok_row[i - 1] + (int)(get(i, 1, i, n) == 0);
    }
    for (int i = 1; i <= n; i++) {
        ok_col[i] = ok_col[i - 1] + (int)(get(1, i, n, i) == 0);
    }
    for (int i = 1; i <= n; i++) {
        for (int x = 1; x <= n - k + 1; x++) {
            up_row[i][x] = up_row[i - 1][x] + (int)(get(i, 1, i, x - 1) + get(i, x + k, i, n) == 0);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int x = 1; x <= n + k - 1; x++) {
            up_col[i][x] = up_col[i - 1][x] + (int)(get(1, i, x - 1, i) + get(x + k, i, n, i) == 0);
        }
    }
    for (int i = 1; i <= n - k + 1; i++) {
        for (int j = 1; j <= n - k + 1; j++) {
            int temp = 0;
            temp += ok_row[i - 1] + ok_row[n] - ok_row[i + k - 1];
            temp += ok_col[j - 1] + ok_col[n] - ok_col[j + k - 1];
            temp += up_row[i + k - 1][j] - up_row[i - 1][j];
            temp += up_col[j + k - 1][i] - up_col[j - 1][i];
            res = max(res, temp);
        }
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