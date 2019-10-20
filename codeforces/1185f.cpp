#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 8;

int pizza[N];
int price[N];
int f[1<<9];
int fr[N];
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        while (x--) {
            int c;
            cin >> c;
            c--;
            fr[i] ^= (1 << c);
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> price[i];
        int x;
        cin >> x;
        while (x--) {
            int c;
            cin >> c;
            c--;
            pizza[i] ^= (1 << c);
        }
    }
    for (int i = 1; i <= m; i++) {
        
    }
}