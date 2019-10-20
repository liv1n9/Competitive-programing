#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int res = 0, j = 1;
    for (int i = n; i >= 1; i--) {
        int l = i * 2 - 1;
        res += l * j;
        if (j < 2) j++;
    }
    cout << res;
}