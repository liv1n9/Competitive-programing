#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int a = 0;
    for (int i = 0; i < s.size(); i++) {
        a += (int)(s[i] == 'a');
    }
    cout << min(a + a - 1, (int)s.size());
}