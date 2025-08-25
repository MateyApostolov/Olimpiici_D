#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n;
    cin >> t;
    int c1[91] = {}, c2[91] = {};
    for(int i = 0; i < t; i++) {
        cin >> n;
        char s1, s2, izc = 0;
        bool iz = true;
        for(int x = 0; x < n; x++) {
            cin >> s1 >> s2;
            if(s1 != s2) iz = false;
            c1[s1 - 33]++;
            c2[s2 - 33]++;
        }

        bool t = true;
        for(int x = 0; x < 91; x++) {
            if(c1[x] != c2[x]) t = false;
            else if(c1[x] > 0) izc++;
        }
        if(iz && izc == 1) cout << 1;
        else if(iz) cout << 0;
        else cout << t;
        c1[91] = {};
        c2[91] = {};
    }

    return 0;
}
