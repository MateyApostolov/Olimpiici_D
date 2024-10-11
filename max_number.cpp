#include <bits/stdc++.h>
using namespace std;

string ng_num(string s1, string s2) {
    if(s1[0] == '-' && s2[0] != '-') return s2;
    if(s2[0] == '-' && s1[0] != '-') return s1;
    string c1 = "", d1 = "", c2 = "", d2 = "";
    bool ch = true;
    for(int i = 0; i < s1.size(); i++) {
        if(s1[i] == '.') {
            ch = false;
            continue;
        }
        if(ch) {
            c1 += s1[i];
        } else {
            d1 += s1[i];
        }
    }
    ch = true;
    for(int i = 0; i < s2.size(); i++) {
        if(s2[i] == '.') {
            ch = false;
            continue;
        }
        if(ch) {
            c2 += s2[i];
        } else {
            d2 += s2[i];
        }
    }
    if(s1[0] != '-') {
        if(c1.size() > c2.size()) return s1;
        if(c1.size() < c2.size()) return s2;
        if(c1 > c2) return s1;
        if(c1 < c2) return s2;
        int i = 0;
        while(i < d1.size() && i < d2.size()) {
            if(d1[i] < d2[i]) return s2;
            if(d1[i] > d2[i]) return s1;
            i++;
        }
    } else {
        if(c1.size() < c2.size()) return s1;
        if(c1.size() > c2.size()) return s2;
        if(c1 < c2) return s1;
        if(c1 > c2) return s2;
        int i = 0;
        while(i < d1.size() && i < d2.size()) {
            if(d1[i] > d2[i]) return s2;
            if(d1[i] < d2[i]) return s1;
            i++;
        }
    }
    return s1;
}

int main () {
    string s, s2 = "";
    getline(cin, s);
    for(int i = 1; i < s.size() - 1; i++) {
        if(s[i] == '.' && (!isdigit(s[i - 1]) || !isdigit(s[i + 1]))) {
            s[i] = ' ';
        } else if(s[i] == '-' && !isdigit(s[i + 1])) {
            s[i] = ' ';
        } else if(!isdigit(s[i]) && s[i] != '-' && s[i] != '.'){
            s[i] = ' ';
        }
    }
    if(!isdigit(s[s.size() - 1])){
        s[s.size() - 1] = ' ';
    }
    if(s[0] == '-' && !isdigit(s[1])) {
        s[0] = ' ';
    } else if(!isdigit(s[0]) && s[0] != '-'){
        s[0] = ' ';
    }
    stringstream ss;
    vector <string> num;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '-') {
            s2 = s2 + ' ' + s[i];
        } else {
            s2 = s2 + s[i];
        }
    }
    ss << s2;
    while(ss >> s2) {
        num.push_back(s2);
    }
    s2 = num[0];
    for(int i = 1; i < num.size(); i++) {
        s2 = ng_num(s2, num[i]);
    }
    cout << s2;
    return 0;
}
