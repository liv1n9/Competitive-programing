#include <bits/stdc++.h>
using namespace std;

mt19937 mt_gen(chrono::high_resolution_clock::now().time_since_epoch().count());
int gen() {
    return abs((int) mt_gen());
}

const string PATTERN = "BCEADCBEDAADCBEBEDCABCADEACEBDCEABDCEBDADBACEDBEACBDAECEACDBDACBEACDEBEADBCBAEDCDEACBCADBEEDBCABEADCBCDEACDEBAECDBACEDABADBCEABCDEBACEDDBAECCBDEADCEABDEABCCBADEBACDEBDCAEACEDBAEBDCACDBEEBCADBAECDECADBCBDAECEADBAEDCBDCABECDAEBBCDAEEACBDADBECADEBCDBCEADABCEEBDACEADCBAEBCDDEBCABECADADECBECBDAEDCBAEABCDDCBEACDBEADCBAECEBADBCEDABADECACBDEDABECDBCAEBDCEADCAEBEBDCAECDABCBAEDBDACEEBCDACBEADADCEBAEDBCDECABECABDEBADCEBACDCAEDBABDECCAEBDEDABCABEDCCABDEABECDBEDACEABDCAECDBECBADABCEDDBECACDABEBDECABEACDCDEABACBEDDEBACBDEACBCAEDDECBAEDCABBECDAEDACBDACEBDCEBADAEBCDAECBCEDBAEDBACCADEBAECBDBADCEABDCECDBAE";
const string KEY = "CABED";

int bound(int l, int r) {
    return l + gen() % (r - l + 1);
}

char query(int i) {
    cout << i << endl;
    char res;
    cin >> res;
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string res = "";
        int limit = 475;
        set<char> choose;
        for (int i = 1; i <= 4; i++) {
            if (limit <= 0) break;
            int pass = 0;
            vector<bool> used(200);
            vector<set<char> > put(200);
            map<char, int> fre;
            while (pass < 5 - i && limit--) {
                int j;
                do {
                    j = bound(1, 119);
                } while (used[j]);
                used[j] = true;
                char c = query((j - 1) * 5 + i);
                if (c == 'N') return 0;
                put[j].insert(c);
                fre[c]++;
                pass += (int)(fre[c] == 24 && choose.find(c) == choose.end());
            }
            for (auto &i: fre) {
                if (i.second < 24 && choose.find(i.first) == choose.end()) {
                    res += i.first;
                    choose.insert(i.first);
                    break;
                }
            }
        }
        for (char c = 'A'; c <= 'E'; c++) {
            if (choose.find(c) == choose.end()) {
                res += c;
                break;
            }
        }
        cout << res << endl;
        char ret;
        cin >> ret;
        if (ret == 'N') {
            return 0;
        }
    }
    return 0;
}