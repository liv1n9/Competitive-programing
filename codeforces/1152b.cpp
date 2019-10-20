#include <bits/stdc++.h>
using namespace std;

bool zero(int x) {
    while (x) {
        if (x & 1 ^ 1) return true;
        x >>= 1;
    }
    return false;
}

int main() {
    int x;
    cin >> x;
    vector<int> res;
    int step = 0;
    while (zero(x)) {
        int y = x;
        int temp = 0;
        while (y && y % 2 == 0) {
            temp++;
            y >>= 1;
        }
        res.push_back(temp);
        step++;
        x ^= ((1 << (temp)) - 1);
        if (zero(x)) {
            x++;
            step++;
        }
    }
    cout << step << endl;
    for (int i: res) cout << i << " ";
}