#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    string s;
    cin >> s;
    int maxbr = 0;
    char izs = 'a';
    for(int i = 0; i < s.size(); i++) {
        int r = i, br = 1;
        while(r < s.size() && s[r] == s[r + 1]) {
            r++;
            br++;
        }
        i = r;
        if(br > maxbr) {
            maxbr = br;
            izs = s[r];
        }
        if(br == maxbr && s[r] > izs) {
            izs = s[r];
        }
    }
    cout << maxbr << " " << izs;
    return 0;
}
