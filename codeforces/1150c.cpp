#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int one, two;
    one = two = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        one += (int)(x == 1);
        two += (int)(x == 2);
    }
    vector<int> a;
    if (one >= 3) {
        one -= 3;
        for (int i = 1; i <= 3; i++) {
            a.push_back(1);
        }
        while (two--) {
            a.push_back(2);
        }
        while (one--) {
            a.push_back(1);   
        }
    } else if (one >= 1 && two >= 1) {
        a.push_back(2);
        a.push_back(1);
        one--;
        two--;
        while (two--) a.push_back(2);
        while (one--) a.push_back(1);
    } else {
        while (two--) a.push_back(2);
        while (one--) a.push_back(1);
    }
    for (int i: a) cout << i << " ";
}