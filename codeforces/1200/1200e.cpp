#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
 
#define INF 1e18
#define EPS 1e-8
 
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
 
const ll BASE = 257;
const ll MOD = 1e9 + 7;
const int N = 1e6 + 8;
 
vector<ll> h1;
ll powr[N];
 
ll get_hash(vector<ll> &h, int l, int r) {
    ll res = h[r];
    if (l > 0) res = (res - h[l - 1] * powr[r - l + 1]) % MOD;
    return res < 0 ? res + MOD : res;
}
 
void solve(int test_number) {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    powr[0] = 1;
    for (int i = 1; i <= 1e6; i++) {
        powr[i] = (powr[i - 1] * BASE) % MOD;
    }
    string s;
    cin >> s;
    for (int i = 0; i < len(s); i++) {
        if (i > 0) {
            h1.push_back((h1.back() * BASE + s[i]) % MOD);
        } else {
            h1.push_back(s[i]);
        }
    }
    string t = s;
    for (int i = 1; i < n; i++) {
        cin >> s;
        vector<ll> h2(len(s));
        for (int j = 0; j < len(s); j++) {
            if (j > 0) {
                h2[j] = (h2[j - 1] * BASE + s[j]) % MOD;
            } else {
                h2[j] = s[j];
            }
        }
        int k = 0;
        for (int x = len(s) - 1; x >= 0; x--) {
            if (x < len(t)) {
                int j = len(t) - 1 - x;
                if (t[j] == s[0]) {
                    if (len(t) - j <= len(s) && get_hash(h1, j, len(t) - 1) == get_hash(h2, 0, len(t) - j - 1)) {
                        k = len(t) - j;
                        break;
                    }
                }
            }
        }
        for (int j = k; j < len(s); j++) {
            if (len(h1) == 0) {
                h1.push_back(s[j]);
            } else {
                h1.push_back((h1.back() * BASE + s[j]) % MOD);
            }
            t += s[j];
        }
    }
    cout << t;
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