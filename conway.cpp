#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s, popr = "";
    int n;
    cin >> s >> n;
    while(n > 0) {
        string news;
        int hs = 0;
        while(hs < s.size()) {
            char rc = s[hs];
            hs++;
            int brp = 1;
            while(hs < s.size() && rc == s[hs]) {
                hs++;
                brp++;
            }
            if(rc - '0' > brp) {
                brp = rc - '0';
            }
            news += char(brp + '0');
            news += rc;
        }
        if(s == news) break;
        if(n % 2 != 0 && popr == news) {
            s = popr;
            break;
        }
        if(n % 2 == 0 && popr == news) break;
        popr = s;
        s = news;
        n--;
    }
    cout << s;
    return 0;
}
