#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, maxbr = 0, br = 0;
    cin >> n;
    int beg[n], en[n];
    string s;
    getline(cin, s);
    for(int i = 0; i < n; i++) {
        getline(cin, s);
        stringstream ss;
        for(int x = 0; x < s.size(); x++) {
            if(s[x] == ':') s[x] = ' ';
        }
        ss << s;
        int h1, m1, s1, h2, m2, s2;
        ss >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
        beg[i] = h1 * 3600 + m1 * 60 + s1;
        en[i] = h2 * 3600 + m2 * 60 + s2;
    }
    sort(beg, beg + n);
    sort(en, en + n);
    int krwr = 24 * 60 * 60, hb = 0, he = 0;
    for(int i = 0; i < krwr; i++) {
        while(hb < n && beg[hb] == i) {
            br++;
            hb++;
        }
        maxbr = max(maxbr, br);
        while(he < n && en[he] == i) {
            br--;
            he++;
        }
    }
    cout << maxbr;
    return 0;
}
