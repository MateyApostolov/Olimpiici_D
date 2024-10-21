#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s, hs, qs;
    vector <string> izs, sps;
    int br = 0, brc = 0, brnc = 0;
    getline(cin, s);
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '.' || s[i] == ',') {
            s[i] = ' ';
        }
    }
    stringstream ss;
    ss << s;
    while(ss >> hs) {
        sort(hs.begin(), hs.end());
        izs.push_back(hs);
    }
    sort(izs.begin(), izs.end());
    while(cin >> qs) {
        sort(qs.begin(), qs.end());
        sps.push_back(qs);
    }
    /*for(int i1 = 0; i1 < sps.size(); i1++) {
        cout << sps[i1] << ' ';
    }
    cout << '\n';
    for(int i1 = 0; i1 < izs.size(); i1++) {
        cout << izs[i1] << ' ';
    }*/
    for(int i1 = 0; i1 < sps.size(); i1++) {
        int h = -1;
        while(h + 1 < izs.size() && sps[i1] != izs[h + 1]) {
            h++;
        }
        if(sps[i1] == izs[h + 1]) {
            br++;
            if(sps[i1].size() % 2 == 0) {
                brc++;
            } else {
                brnc++;
            }
        }
    }
    cout << br << '\n' << brc << ' ' << brnc;
    return 0;
}
