#include <bits/stdc++.h>
using namespace std;

bool c[10];

string cn (string st, int h) {
    for(int x = 0; x < st.size(); x++) {
        if(st[x] == '?') st[x] = h + '0';
    }
    return st;
}

int main () {
    string s;
    cin >> s;
    stringstream ss;
    string n1, n2, n3, h1, h2, h3;
    char z = '1';
    for(int i = 0; i < s.size(); i++) {
        if(isdigit(s[i])) {
            c[s[i] - '0'] = true;
        }
        if(s[i] == '+') {
            z = '+';
            s[i] = ' ';
        }
        if(s[i] == '*') {
            z = '*';
            s[i] = ' ';
        }
        if(s[i] == '=') {
            s[i] = ' ';
        }
        if(i != 0 && z == '1' && s[i] == '-') {
            z = '-';
            s[i] = ' ';
        }
    }
    ss << s;
    ss >> h1 >> h2 >> h3;
    for(int i = 0; i <= 9; i++) {
        if(h1[0] == '?' && h1.size() > 1 && i == 0) continue;
        if(h2[0] == '?' && h2.size() > 1 && i == 0) continue;
        if(h3[0] == '?' && h3.size() > 1 && i == 0) continue;
        if(c[i]) continue;
        n1 = cn(h1, i);
        n2 = cn(h2, i);
        n3 = cn(h3, i);
        int a, b, c;
        ss.clear();
        ss << n1;
        ss >> a;
        ss.clear();
        ss << n2;
        ss >> b;
        ss.clear();
        ss << n3;
        ss >> c;
        if(z == '+' && a + b == c) {
            cout << i;
            return 0;
        }
        if(z == '-' && a - b == c) {
            cout << i;
            return 0;
        }
        if(z == '*' && a * b == c) {
            cout << i;
            return 0;
        }
    }
    cout << "mistake";
    return 0;
}
