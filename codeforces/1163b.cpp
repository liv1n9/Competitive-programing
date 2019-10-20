#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    int m = 0;
    for (int &i: a) {
        cin >> i;
        m = max(m, i);
    }
    map<int, int> fre;
    vector<int> f(m + 1);
    int res = 0;
    for (int i = 0; i < n; i++) {
        int pre = f[a[i]];
        if (fre.find(pre) != fre.end()) {
            fre[pre]--;
            if (fre[pre] == 0) {
                fre.erase(pre);
            }
        }
        f[a[i]]++;
        fre[f[a[i]]]++;
        if (fre.size() == 2) {
            vector<pair<int, int> > temp;
            for (auto &j: fre) {
                temp.push_back(j);
            }
            if (temp[0].first == 1 && temp[0].second == 1) {
                res = i + 1;
            }
            if (temp[1].first == temp[0].first + 1 && temp[1].second == 1) {
                res = i + 1;
            }
        } else if (fre.size() == 1 && (fre.begin()->first == 1 || fre.begin()->second == 1)) {
            res = i + 1;
        }
    }
    cout << res;
}