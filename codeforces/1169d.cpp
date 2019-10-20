#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 8;

char s[N];
int p[N];
int n = 0;

int main() {
    cin >> s + 1;
    while (s[n + 1]) n++;
    vector<pair<int, int> > c;
    for (int k = 1; k <= 100; k++) {
        for (int i = 1; i <= n; i++) {
            if (i + 2 * k <= n) {
                if (s[i] == s[i + k] && s[i + k] == s[i + 2 * k]) {
                    p[i + 2 * k] = max(p[i + 2 * k], i);
                }
            }
        }
    }
    for (int i = 3; i <= n; i++) {
        p[i] = max(p[i], p[i - 1]);
    }
    long long res = 0;
    for (int i = 3; i <= n; i++) {
        res += p[i];
    }
    cout << res;
}