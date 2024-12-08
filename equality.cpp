#include <bits/stdc++.h>
using namespace std;

long long sb (string s, int os) {
    long long sum = 0;
    for(long long i = 0; i < s.size(); i++) {
        if(isdigit(s[i])) {
            sum += (s[i] - '0') * pow(os, i);
        } else {
            sum += (s[i] - 'A' + 10) * pow(os, i);
        }
    }
    return sum;
}

int maxC(string st){
    int os = 0;
    for(int i = 0; i < st.size(); i++) {
        if(isdigit(st[i])) {
            os = max(os,st[i] - '0');
        } else {
            os = max(os,st[i] - 'A' + 10);
        }
    }
    os++;
    return os;
}

int main () {
    string s, s1, s2, eq;
    cin >> s;
    for(long long i = 0; i < s.size(); i++) {
        if(s[i] == '+' || s[i] == '=') {
            s[i] = ' ';
        }
    }
    stringstream ss;
    ss << s;
    ss >> s1 >> s2 >> eq;
    int os = max(maxC(s1), max(maxC(s2), maxC(eq)));
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    reverse(eq.begin(), eq.end());
    while(true) {
        int sb1, sb2, eq3;
        sb1 = sb(s1, os);
        sb2 = sb(s2, os);
        eq3 = sb(eq, os);
        if(sb1 + sb2 == eq3) break;
        os++;
    }
    cout << os;
    return 0;
}
