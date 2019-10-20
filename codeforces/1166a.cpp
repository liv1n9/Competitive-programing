#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<char, int> fre;
    while (n--) {
        string s;
        cin >> s;
        fre[s[0]]++;
    }
    int res = 0;
    for (auto &i: fre) {
        int tmp = 1e9;
        for (int j = 0; j <= i.second; j++) {
            int k = i.second - j;
            tmp = min(tmp, j * (j - 1) / 2 + k * (k - 1) / 2);
        }
        res += tmp;
    }
    cout << res;
}