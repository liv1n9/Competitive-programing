#include <bits/stdc++.h>
using namespace std;

set<string> cards;
vector<string> x = {
    "1", 
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "10",
    "11",
    "12",
    "13"
};
vector<string> y = {"R", "C", "B", "T"};

vector<set<string> > p[10];
vector<set<string> > u_ok;

void preprocess() {
    for (string n: x) {
        for (string i: y) {
            for (string j: y) {
                for (string k: y) {
                    if (i < j && j < k) {
                        set<string> temp = {n + i, n + j, n + k};
                        p[3].push_back(temp);
                    }
                }
            }
        }
    }
    for (int t = 3; t <= 6; t++) {
        for (int i = 0; i + t - 1 < 13; i++) {
            for (string j: y) {
                set<string> temp;
                for (int k = 0; k < t; k++) {
                    temp.insert(x[i + k] + j);
                }
                p[t].push_back(temp);
            }
        }
    }
    for (int i = 3; i <= 4; i++) {
        for (auto &s_1: p[i]) {
            for (auto &s_2: p[9 - i]) {
                set<string> temp;
                for (auto &k: s_1) {
                    temp.insert(k);
                }
                for (auto &k: s_2) {
                    temp.insert(k);
                }
                if (temp.size() == 9) {
                    u_ok.push_back(temp);
                }
            }
        }
    }
    for (int i = 0; i < p[3].size(); i++) {
        set<string> temp;
        for (auto &k: p[3][i]) {
            temp.insert(k);
        }
        for (int j = i + 1; j < p[3].size(); j++) {
            bool ok = true;
            for (auto &k: p[3][j]) {
                if (temp.find(k) != temp.end()) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                set<string> temp_1 = temp;
                for (auto &k: p[3][j]) {
                    temp_1.insert(k);
                }
                for (int k = j + 1; k < p[3].size(); k++) {
                    bool ok_1 = true;
                    for (auto &x: p[3][k]) {
                        if (temp_1.find(x) != temp_1.end()) {
                            ok_1 = false;
                            break;
                        }
                    }
                    if (ok_1) {
                        auto temp_2 = temp_1;
                        for (auto &x: p[3][k]) {
                            temp_2.insert(x);
                        }
                        u_ok.push_back(temp_2);
                    }
                }
            }
        }
    }
}

int cardGroupNumber(std::string s)
{
    preprocess();
    int res = INT_MAX;
    for (auto &s_u: u_ok) {
        int temp = 0;
        for (int i = 1; i < s.size(); i += 2) {
            string b = "";
            b = b + (char) s[i - 1];
            b = b + (char) s[i];
            temp += (int) (s_u.find(b) == s_u.end());
        }
        res = min(res, temp);
    }
    return res;
}

int main() {
    freopen(".out", "w", stdout);
    preprocess();
    for (auto &i: u_ok) {
        cout << "{";
        for (auto &j: i) {
            cout << '\"' << j << "\"," ; 
        }
        cout << "},";
    }
}