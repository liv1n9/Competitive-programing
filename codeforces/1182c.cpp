#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 8;
string s[N];
map<pair<int, char>, vector<int> > last;
map<int, vector<int> > first;
bool candidate[N];
bool used[N];
vector<int> last_can;
vector<int> first_res, last_res;

bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        char c;
        cin >> s[i];
        for (int j = 0; j < s[i].size(); j++) {
            if (is_vowel(s[i][j])) {
                cnt++;
                c = s[i][j];
            }
        }
        if (cnt > 0) {
            last[{cnt, c}].push_back(i);
        }
    }
    for (auto &e: last) {
        for (int i = 1; i < e.second.size(); i += 2) {
            candidate[e.second[i - 1]] = true;
            candidate[e.second[i]] = true;
            last_can.push_back(e.second[i - 1]);
            last_can.push_back(e.second[i]);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!candidate[i]) {
            int cnt = 0;
            for (int j = 0; j < s[i].size(); j++) {
                cnt += (int) is_vowel(s[i][j]);
            }
            if (cnt > 0) {
                first[cnt].push_back(i);
            }
        }
    }
    int l = 0;
    for (auto &e: first) {
        for (int i = 1; i < e.second.size(); i += 2) {
            if (l + 2 <= last_can.size()) {
                first_res.push_back(e.second[i - 1]);
                first_res.push_back(e.second[i]);
                last_res.push_back(last_can[l++]);
                last_res.push_back(last_can[l++]);
            } else {
                break;
            }
        }
    }
    if (l + 4 <= last_can.size()) {
        for (int i = l + 3; i < last_can.size(); i += 4) {
            first_res.push_back(last_can[i - 3]);
            first_res.push_back(last_can[i - 2]);
            last_res.push_back(last_can[i - 1]);
            last_res.push_back(last_can[i - 0]);
        }
    }
    cout << first_res.size() / 2 << endl;
    for (int i = 0; i < first_res.size(); i++) {
        cout << s[first_res[i]] << " " << s[last_res[i]] << endl;
    }
}