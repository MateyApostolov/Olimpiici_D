#include <bits/stdc++.h>
using namespace std;

pair <int, char> b[26];

void brb(string s) {
    for(int i = 0; i < 26; i++) {
        b[i] = {0, 'a' + i};
    }
    for(int i = 0; i < s.size(); i++)  {
        b[s[i] - 'a'].first++;
    }
    sort(b, b + 26);
    return;
}

int main () {
    string s;
    cin >> s;
    brb(s);
    for(int i = 2; i < s.size(); i++) {
        if(s[i] == s[i - 1] && s[i] == s[i - 2]) {
            int hb = 0;
            while(s[i] == b[hb].second || (i + 1 < s.size() && s[i + 1] == b[hb].second)) {
                hb++;
            }
            s[i] = b[hb].second;
        }
    }
    brb(s);
    while(b[25].first > s.size() / 2) {
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == b[25].second) {
                int hb = 0;
                while(s[i - 1] == b[hb].second || (i + 1 < s.size() && s[i + 1] == b[hb].second)) {
                    hb++;
                }
                s[i] = b[hb].second;
                break;
            }
        }

        brb(s);
    }
    cout << s;
    return 0;
}
