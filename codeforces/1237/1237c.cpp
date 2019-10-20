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

struct point {
    int x, y, z, i;
};

bool cmp(const point &p1, const point &p2) {
    tuple<int, int, int, int> a = make_tuple(p1.x, p1.y, p1.z, p1.i);
    tuple<int, int, int, int> b = make_tuple(p2.x, p2.y, p2.z, p2.i);
    return a < b;
}

bool ok(const vector<point> &a) {
    for (int i = 1; i + 2 < a.size(); i += 2) {
        int x1 = min(a[i - 1].x, a[i].x);
        int x2 = max(a[i - 1].x, a[i].x);
        int y1 = min(a[i - 1].y, a[i].y);
        int y2 = max(a[i - 1].y, a[i].y);
        int z1 = min(a[i - 1].z, a[i].z);
        int z2 = max(a[i - 1].z, a[i].z);
        for (int j = i + 1; j < a.size(); j++) {
            if (a[j].x >= x1 && a[j].x <= x2 && a[j].y >= y1 && a[j].y <= y2 && a[j].z >= z1 && a[j].z <= z2) {
                return false;
            }
        }
    }
    return true;
}

int calc(const vector<point> &a) {
    for (int i = 1; i < a.size(); i++) {
        int x1 = min(a[0].x, a[i].x);
        int x2 = max(a[0].x, a[i].x);
        int y1 = min(a[0].y, a[i].y);
        int y2 = max(a[0].y, a[i].y);
        int z1 = min(a[0].z, a[i].z);
        int z2 = max(a[0].z, a[i].z);
        bool ok = true;
        for (int j = 1; j < a.size(); j++) {
            if (j != i && a[j].x >= x1 && a[j].x <= x2 && a[j].y >= y1 && a[j].y <= y2 && a[j].z >= z1 && a[j].z <= z2) {
                ok = false;
                break;
            }
        }
        if (ok) {
            return i;
        }
    }
    return 0;
}

void solve(int test_number) {
    int n;
    cin >> n;
    vector<point> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].z;
        a[i].i = i + 1;
    }
    sort(all(a), &cmp);
    for (int i = 0; i < n; i += 2) {
        vector<point> temp;
        for (int j = i; j < min(n, i + 9); j++) {
            temp.push_back(a[j]);
        }
        int k = calc(temp) + i;
        auto t = a[k];
        for (int j = k; j > i + 1; j--) {
            swap(a[j], a[j - 1]);
        }
        a[i + 1] = t;
        cout << a[i].i << " " << a[i + 1].i << endl;
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