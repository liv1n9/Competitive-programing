#include <bits/stdc++.h>
using namespace std;

int ask(int i, int j) {
    cout << "? " << i << " " << j << endl;
    int x;
    cin >> x;
    return x;
}

int main() {
    // 4 15 23 8 42 16
    vector<int> s = {4, 8, 15, 16, 23, 42};
    vector<int> b(4);
    b[0] = ask(1, 2);
    b[1] = ask(2, 3);
    b[2] = ask(4, 5);
    b[3] = ask(5, 6);
    do {
        if (b[0] == s[0] * s[1] && b[1] == s[1] * s[2] && b[2] == s[3] * s[4] && b[3] == s[4] * s[5]) {
            break;
        }
    } while (next_permutation(s.begin(), s.end()));
    cout << "!";
    for (int i: s) {
        cout << " " << i;
    }
    cout << endl;
}