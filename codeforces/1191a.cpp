#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    set<pair<char, int> > s;
    for (int i = 0; i <= 2; i++) {
        int m = n + i;
        if (m % 4 == 1) {
            s.insert({'A', i});
        } else if (m % 4 == 3) {
            s.insert({'B', i});
        } else if (m % 4 == 2) {
            s.insert({'C', i});
        } else {
            s.insert({'D', i});
        }
    }
    cout << s.begin()->second << " " << s.begin()->first;
}