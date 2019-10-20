#include <bits/stdc++.h>
using namespace std;

vector<char> t = {'m', 's', 'p'};

int main() {
    map<string, int> f;
    string a;
    for (int i = 0; i < 3; i++) {
        cin >> a;
        f[a]++;
    }
    int res = INT_MAX;
    int temp = 0;
    for (char i = '1'; i <= '9'; i++) {
        for (char j: t) {
            string s;
            s += i;
            s += j;
            // cerr << s << endl;
            temp = max(temp, f[s]);
        }
    }
    res = max(0, 3 - temp);
    temp = 0;
    for (int i = '1'; i <= '7'; i++) {
        for (char j: t) {
            string x, y, z;
            x += i;
            x += j;
            y += (char)(i + 1);
            y += j;
            z += (char)(i + 2);
            z += j;
            int sum = min(1, f[x]) + min(1, f[y]) + min(1, f[z]);
            temp = max(temp, sum);
        }
    }
    res = min(res, max(0, 3 - temp));
    cout << res;
}