#include <bits/stdc++.h>
using namespace std;

int brs[26], brb[26], brnc;

int main () {
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if(isupper(s[i])) {
            brb[s[i] - 'A']++;
        } else {
            brs[s[i] - 'a']++;
        }
    }
    for(int i = 0; i < 26; i++) {
        if(brs[i] % 2 != 0) {
            brnc++;
        }
        if(brb[i] %2 != 0) {
            brnc++;
        }
    }
    if(brnc == 0) {
        brnc = 1;
    }
    cout << brnc;
    return 0;
}

