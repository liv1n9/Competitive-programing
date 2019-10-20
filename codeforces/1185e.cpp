#include <bits/stdc++.h>
using namespace std;

const int N = 2008;
char s[N][N];
int n, m;
vector<pair<int, int> > heads, tails;

string calc() {
    set<pair<int, int> > mystery;
    heads.clear();
    tails.clear();
    map<char, set<pair<int, int> > > point;
    set<char> snakes;
    char cm = ' ';
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] != '.') {
                point[s[i][j]].insert({i, j});
                cm = max(cm, s[i][j]);
            }
        }
    }
    if (cm == ' ') return "YES";
    for (char snake = cm; snake >= 'a'; snake--) {
        if (point[snake].size() == 0) {
            if (mystery.empty()) {
                return "NO";
            }
            pair<int, int> head = *mystery.begin();
            heads.push_back(head);
            tails.push_back(head);
            continue;
        }
        pair<int, int> head = *point[snake].begin();
        pair<int, int> tail = *point[snake].rbegin();
        if (head.first != tail.first && head.second != tail.second) {
            return "NO";
        }
        vector<pair<int, int> > sk;
        if (head.first == tail.first) {
            for (int i = head.second; i <= tail.second; i++) {
                sk.push_back({head.first, i});
            }
        } else {
            for (int i = head.first; i <= tail.first; i++) {
                sk.push_back({i, head.second});
            }
        }
        int cnt1 = 0;
        int cnt2 = 0;
        for (pair<int, int> &i: sk) {
            cnt1 += (int) (mystery.find(i) != mystery.end() || point[snake].find(i) != point[snake].end());
            cnt2 += (int) (point[snake].find(i) != point[snake].end());
        }
        if (cnt1 == sk.size() && cnt2 == point[snake].size()) {
            for (pair<int, int> &i: sk) {
                mystery.insert(i);
            }
            heads.push_back(head);
            tails.push_back(tail);
        } else {
            return "NO";
        }
    }
    return "YES";
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> s[i] + 1;
        }
        string flag = calc();
        cout << flag << endl;
        if (flag[0] == 'Y') {
            cout << heads.size() << endl;
            reverse(heads.begin(), heads.end());
            reverse(tails.begin(), tails.end());
            for (int i = 0; i < heads.size(); i++) {
                cout << heads[i].first << " " << heads[i].second << " " << tails[i].first << " " << tails[i].second << endl;
            }
        }
    }
}