#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> t(n);
    vector<int> fre(101);
    for (int &i: t) {
        scanf("%d", &i);
    }
    vector<int> res(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += t[i];
        int rest = sum - m;
        int x = 0;
        for (int j = 100; j >= 1 && rest > 0; j--) {
            int z = min(fre[j], (rest + j - 1) / j);
            rest -= j * z;
            x += z;
        }
        res[i] = x;
        fre[t[i]]++;
    }
    for (int i: res) {
        printf("%d ", i);
    }
}