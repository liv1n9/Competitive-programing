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

int n, m, k;
set<int> pos_x[N], neg_x[N], pos_y[N], neg_y[N];

void solve(int test_number) {
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        int x, y;
        cin >> x >> y;
        pos_x[x].insert(y);
        neg_x[x].insert(-y);
        pos_y[y].insert(x);
        neg_y[y].insert(-x);
    }
    int lx = 0, rx = n + 1;
    int ly = 0, ry = m + 1;
    int x = 1, y = 1;
    int p = 0;
    ll step = 1;
    set<pair<int, int> > pos;
    pos.insert({1, 1});
    while (true) {
        set<int>::iterator it;
        set<int>::iterator last;
        if (p == 0) {
            it = pos_x[x].upper_bound(y);
            last = pos_x[x].end();
        } else if (p == 1) {
            it = pos_y[y].upper_bound(x);
            last = pos_y[y].end();
        } else if (p == 2) {
            it = neg_x[x].upper_bound(-y);
            last = neg_x[x].end();
        } else {
            it = neg_y[y].upper_bound(-x);
            last = neg_y[y].end();
        }
        if (p == 0) {
            if (it != last) {
                step += (*it) - y - 1;
                ry = (*it) - 1;
            } else {
                step += ry - y - 1;
                ry -= 1;
            }
            y = ry;
        } else if (p == 1) {
            if (it != last) {
                step += (*it) - x - 1;
                rx = (*it) - 1;
            } else {
                step += rx - x - 1;
                rx -= 1;
            }
            x = rx;
        } else if (p == 2) {
            if (it != last) {
                step += (*it) + y - 1;
                ly = 1 - (*it);
            } else {
                step += y - ly - 1;
                ly += 1;
            }
            y = ly;
        } else {
            if (it != last) {
                step += (*it) + x - 1;
                lx = 1 - (*it);
            } else {
                step += x - lx - 1;
                lx += 1;
            }
            x = lx;
        }
        p = (p + 1) % 4;
        debug(x, y);
        if (!pos.insert({x, y}).second) {
            break;
        }
    }
    debug(step, n * m - k);
    if (step == (ll) n * m - k) {
        cout << "Yes";
    } else {
        cout << "No";
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