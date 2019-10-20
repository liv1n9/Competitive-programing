#include <bits/stdc++.h>
using namespace std;

vector<char> v = {'a', 'e', 'i', 'o', 'u'};

int main() {
    int k;
    cin >> k;
    for (int i = 5; i <= k; i++) {
        if (k % i == 0 && k / i >= 5) {
            vector<int> pre(k / i);
            for (int y = 0; y < k / i; y++) {
                pre[y] = y % 5;
            }
            for (int x = 0; x < i; x++) {
                for (int y = 0; y < k / i; y++) {
                    pre[y] = (pre[y] + 1) % 5;
                    cout << v[pre[y]];
                }
            }
            return 0;
        }
    }
    cout << -1;
}