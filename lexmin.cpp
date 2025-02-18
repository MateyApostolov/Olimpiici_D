#include <bits/stdc++.h>
using namespace std;

bool brc[26];

int main () {
    string s;
    cin >> s;
    char c = 'a', u = '/';
    int brd = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'd') brd++;
        else {
            c += brd;
            for(int x = brd; x >= 0; x--) {
                cout << c;
                c--;
            }
            if(u == '/') {
                u = char('a' + 2 * brd + 1);
            } else {
                u = char(u + brd + 1);
            }
            cout << u;
            brd = 0;
        }
    }
    for(int x = brd; x >= 0; x--) {
        cout << c;
        c--;
    }
    return 0;
}
