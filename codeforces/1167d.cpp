#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    cin >> s;
    stack<int> s1, s2;
    int cur = 0;
    vector<int> res(n);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            if (s1.size() < s2.size()) {
                s1.push(i);
                res[i] = 0;
            } else {
                s2.push(i);
                res[i] = 1;
            }
        } else {
            if (!s1.empty()) {
                if (s2.empty() || s1.top() > s2.top()) {
                    res[i] = 0;
                    s1.pop();
                } else {
                    res[i] = 1;
                    s2.pop();
                }
            } else {
                res[i] = 1;
                s2.pop();
            }
        }
    }
    for (int i: res) {
        cout << i;
    }
}