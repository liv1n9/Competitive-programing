#include <bits/stdc++.h>
using namespace std;

const int TIME = 245509;

char win(char c) {
    if (c == 'P') return 'R';
    if (c == 'R') return 'S';
    return 'P';
}

char lose(char c) {
    if (c == 'P') return 'S';
    if (c == 'R') return 'P';
    return 'R';
}

int main() {
    int test;
    cin >> test;
    for (int t = 1; t <= test; t++) {
        int n;
        cin >> n;
        vector<string> s(n);
        string res;
        for (auto &i: s) {
            cin >> i;
        }
        vector<bool> won(n);
        bool ok = false;
        for (int i = 0; i < TIME; i++) {
            if (res.size() < 500) {
                set<char> c;
                for (int j = 0; j < n; j++) {
                    if (won[j]) continue;
                    c.insert(s[j][i % s[j].size()]);
                }
                if (c.size() != 2) {
                    ok = c.size() == 1;
                    res += lose(*c.begin());
                    break;
                } else {
                    vector<char> d;
                    for (auto &j: c) d.push_back(j);
                    char last;
                    if (win(d[0]) == d[1]) {
                        last = d[0];
                    } else {
                        last = d[1];
                    }
                    res += last;                
                    for (int j = 0; j < n; j++) {
                        if (won[j]) continue;
                        won[j] = win(last) == s[j][i % s[j].size()];
                    }
                }
            } else {
                bool pass = false;
                bool fail = false;
                for (int j = 0; j < n; j++) {
                    if (won[j]) continue;
                    if (win(res[i % 500]) == s[j][i % s[j].size()]) {
                        pass = true;
                    } else if (lose(res[i % 500]) == s[j][i % s[j].size()]) {
                        fail = true;
                    }
                }
                if (fail) break;
                if (pass) {
                    ok = true;
                    break;
                }
            }
        }
        cout << "Case #" << t << ": ";
        if (ok) cout << res;
        else cout << "IMPOSSIBLE";
        cout << endl;
    }    
}