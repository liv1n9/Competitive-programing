#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    k--;
    vector<int> a(n);
    for (int &i: a) {
        scanf("%d", &i);
    }
    priority_queue<long long> q;
    reverse(a.begin(), a.end());
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (i + 1 < n) q.push(sum);
    }
    while (k--) {
        sum += q.top();
        q.pop();
    }
    cout << sum;
}