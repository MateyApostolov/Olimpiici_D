#include <bits/stdc++.h>
using namespace std;

int main () {
    string s;
    cin >> s;
    int br = 0, ngbr = 0, h = 0;
    char cb = 'a';
    for(int i = 0; i < s.size();) {
        while(h < s.size() && s[i] == s[h]) h++;
        ///cout << h << " " << i << "\n";
        br = h - i;
        if(ngbr < br || (ngbr == br && s[i] > cb)) {
            ngbr = br;
            cb = s[i];
        }
        i = h;
    }
    cout << ngbr << " " << cb;
    return 0;
}
