#include <bits/stdc++.h>
using namespace std;

int main () {
    string s;
    cin >> s;
    int bru = 0, brl = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'L') brl++;
        if(s[i] == 'R') brl--;
        if(s[i] == 'U') bru++;
        if(s[i] == 'D') bru--;
    }
    if(bru > 0) {
        for(int i = 0; i < bru; i++) cout << 'D';
    }
    if(bru < 0) {
        for(int i = 0; i < abs(bru); i++) cout << 'U';
    }
    if(brl > 0) {
        for(int i = 0; i < brl; i++) cout << 'R';
    }
    if(brl < 0) {
        for(int i = 0; i < abs(brl); i++) cout << 'L';
    }
    if(bru == 0 && brl == 0) cout << 0;
    return 0;
}
