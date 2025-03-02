#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    string s;
    cin >> n >> s;
    int c = 1;
    int br = 0, i;
    while(br < s.size()) {
        i = 0;
        while(br + i < s.size() && s[br + i] == '>') i++;
        c += i;
        if(i != 0) {
            for(int x = 0; x <= i; x++) cout << c - x << ' ';
            i++;
            br += i;
            c++;
        }
        i = 0;
        while(br + i < s.size() && s[br + i] == '<') i++;
        if(i != 0) {
            for(int x = 0; x < i; x++) {
                cout << c << ' ';
                c++;
            }
            br += i;
        }
    }
    if(s[s.size() - 1] == '<') cout << c << ' ';

    return 0;
}
