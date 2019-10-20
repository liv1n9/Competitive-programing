#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 8;
vector<tuple<int, long long, int> > a[N];
long long dp[N][10];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        vector<vector<int> > b(4);
        int temp = 0;
        for (int j = 1; j <= k; j++) {
            int c, d;
            cin >> c >> d;
            b[c].push_back(d);
            temp = max(temp, d);
        }
        a[i].push_back(make_tuple(0, 0, 0));
        a[i].push_back(make_tuple(1, temp, temp));
        sort(b[1].rbegin(), b[1].rend());
        if (b[1].size() >= 3) {
            a[i].push_back(make_tuple(3, (long long)b[1][0] + b[1][1] + b[1][2], b[1][0]));
        }
        sort(b[2].rbegin(), b[2].rend());
        vector<int>com;
        if (b[1].size() > 0) {
            com.push_back(b[1][0]);
            if (b[1].size() > 1) {
                com.push_back(b[1][1]);
            }
        }
        if (b[2].size() > 0) {
            com.push_back(b[2][0]);
        }
        sort(com.rbegin(), com.rend());
        if (com.size() >= 2) {
            a[i].push_back(make_tuple(2, com[0] + com[1], com[0]));
        }
    }
    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            for (auto &e: a[i]) {
                int x, z;
                long long y;
                tie(x, y, z) = e;
                x = (j - x + 10) % 10;
                if (dp[i - 1][x] != -1) {
                    if (j < x) {
                        y += z;
                    }
                    dp[i][j] = max(dp[i][j], dp[i - 1][x] + y);
                }
            }
        }
    }
    long long res = 0;
    for (int i = 0; i < 10; i++) {
        res = max(res, dp[n][i]);
    }
    cout << res;
}