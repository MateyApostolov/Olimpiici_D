#include <bits/stdc++.h>
using namespace std;

bool brc[26];

int main () {
    string s;
    cin >> s;
    char c = 'a';
    int br = 0, i;
    while(br < s.size()) {
        i = 0;
        while(br + i < s.size() && s[br + i] == 'd') i++;
        c += i;
        if(i != 0) {
            for(int x = 0; x <= i; x++) cout << char(c - x);
            i++;
            br += i;
            c++;
        }
        i = 0;
        while(br + i < s.size() && s[br + i] == 'u') i++;
        if(i != 0) {
            for(int x = 0; x < i; x++) {
                cout << c;
                c++;
            }
            br += i;
        }
    }
    if(s[s.size() - 1] == 'u') cout << c;

    return 0;
}
