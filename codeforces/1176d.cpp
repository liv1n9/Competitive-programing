#include <bits/stdc++.h>
using namespace std;

const int N = 2750132;
int e[N], fre[N];
vector<int> p(1);

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 2; i < N; i++) {
        if (e[i] == 0) {
            p.push_back(i);
            for (int j = i; j < N; j += i) {
                if (e[j] == 0) {
                    e[j] = i;
                }
            }
        }
    }
    for (int i = 1; i <= n * 2; i++) {
        int x;
        scanf("%d", &x);
        fre[x]++;
    }
    for (int i = N - 1; i >= 2; i--) {
        if (fre[i] > 0 && e[i] != i) {
            fre[max(e[i], i / e[i])] -= fre[i];
            for (int j = 0; j < fre[i]; j++) { 
                printf("%d ", i);
            }
            fre[i] = 0;
        }
    }
    for (int i = 2; i < N; i++) {
        if (fre[i] > 0) {
            while (fre[i]--) {
                printf("%d ", i);
                fre[p[i]]--;
            }
        }
    }
}