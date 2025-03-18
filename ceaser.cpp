#include <bits/stdc++.h>
using namespace std;

int main () {
    string s;
    int n;
    getline(cin, s);
    cin >> n;
    n %= 26;
    if(n < 0) n += 26;
    for(int i = 0; i < s.size(); i++) {
        if(isalpha(s[i])) {
            char c = 'a';
            if(isupper(s[i])) c = 'A';
            int x = s[i] - c - n;
            if(x < 0) x += 26;
            s[i] = char(c + x);
        }
    }
    cout << s;
    return 0;
}

