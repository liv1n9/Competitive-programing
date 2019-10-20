#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int eight = 0;
    for (int i = 0; i < n; i++) {
        eight += (int)(s[i] == '8');
    }
    int move = n - 11;
    if (eight == 0) {
        cout << "NO";
        return 0;
    }
    if (move / 2 < eight) {
        int temp = 0;
        int pass = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '8') {
                if (pass == move / 2) {
                    break;
                }
                pass++;
            } else {
                temp++;
            }
        }
        cout << (temp <= move / 2 ? "YES" : "NO");
    } else {
        cout << "NO";
        return 0;
    }
}