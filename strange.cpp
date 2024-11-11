#include <bits/stdc++.h>
using namespace std;

int brs[256];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    int r = -1, maxbr = 0, lh;
    for(int l = 0; l < s.size(); l++) {
        while(r + 1 < s.size() && brs[s[r + 1]] == 0) {
            r++;
            brs[s[r]]++;
        }
        if(r - l + 1 >= maxbr) {
            maxbr = r - l + 1;
            lh = l;
        }
        brs[s[l]]--;
    }
    cout << maxbr << ' ' << lh << '\n' << s.substr(lh, maxbr);

    return 0;
}
