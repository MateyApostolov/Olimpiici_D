#include <bits/stdc++.h>
using namespace std;

int main () {
    string s;
    cin >> s;
    while(!s.empty()) {
        string news = "", hs = "";
        hs += s[0];
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == s[i - 1]) hs += s[i];
            else {
                if(hs.size() <= 2) news += hs;
                hs.clear();
                hs += s[i];
            }
        }
        if(hs.size() <= 2) news += hs;
        if(s == news) break;
        s = news;
    }
    if(s.empty()) cout << "EMPTY";
    else cout << s;
    return 0;
}
