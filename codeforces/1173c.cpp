#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 8;
int a[N], b[N];
int n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", b + i);
    }
    bool flag = true;
    bool clear = true;
    int last = n;
    for (int i = 1; i <= n; i++) {
        if (b[i] == 1) {
            last = i - 1;
            for (int j = i + 1; j <= n; j++) {
                if (b[j] != b[i] + j - i) {
                    flag = false;
                    break;
                }
            }
            break;
        } else {
            clear &= (b[i] == 0 || i < b[i]);
        }
    }
    if (flag && clear) {
        cout << last;
        return 0;
    }
    int dec = 0;
    for (int i = 1; i <= n; i++) {
        if (b[i] > 0) {
            dec = max(dec, i - b[i] + 1);
        }
    }
    cout << dec + n;
}