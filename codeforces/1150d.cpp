#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 8;
const int M = 258;

char st[3][M];
int len[3];
int start[3];
char s[N];
int n, q;

int main() {
    srand(time(NULL));
    ios::sync_with_stdio(false);
    cin >> n >> q;
    cin >> s + 1;
    while (q--) {
        char c;
        int x;
        cin >> c >> x;
        x--;
        if (c == '+') {
            char e;
            cin >> e;
            len[x]++;
            st[x][len[x]] = e;
        } else {
            --len[x];
        }
        bool res = false;
        for (int it = 1; it <= 5; it++) {
            start[0] = start[1] = start[2] = 1;
            for (int i = 1; i <= n; i++) {
                vector<int> p = {0, 1, 2};
                random_shuffle(p.begin(), p.end());
                for (int j = 0; j < 3; j++) {
                    if (start[p[j]] <= len[p[j]] && s[i] == st[p[j]][start[p[j]]]) {
                        start[p[j]]++;
                        break;
                    }
                }
            }
            bool ok = true;
            for (int i = 0; i < 3; i++) {
                if (start[i] <= len[i]) {
                    ok = false;
                }
            }
            res |= ok;
            if (res) break;
        }
        cout << (res ? "YES\n" : "NO\n");
    }
}