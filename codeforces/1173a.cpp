#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    set<int> res;
    for (int i = 0; i <= z; i++) {
        if (x + i < y + z - i) res.insert(-1);
        if (x + i == y + z - i) res.insert(0);
        if (x + i > y + z - i) res.insert(1);
    }
    if (res.size() > 1) {
        cout << "?";
        return 0;
    }
    x = *res.begin();
    if (x == -1) cout << "-";
    if (x == 0) cout << 0;
    if (x == 1) cout << "+";
}