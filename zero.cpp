#include <bits/stdc++.h>
using namespace std;

int main () {
    string s;
    cin >> s;
    int r = 0;
    unordered_map <int, int> dif;
    for(int i1 = 1; i1 < s.size(); i1++) {
        if(s[i1 - 1] == '1' && s[i1] == '0') {
            r++;
        }
        if(s[i1 - 1] == '0' && s[i1] == '0') {
            r++;
        }
        if(s[i1 - 1] == '0' && s[i1] == '1') {
            dif[r]++;
            r = 0;
        }
    }
    if(s[s.size() - 1] == '0') {
        dif[r]++;
    }
    cout << dif.size();

    return 0;
}
