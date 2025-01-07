#include <bits/stdc++.h>
using namespace std;

void print (vector <char>& num) {
    for(int i = num.size() - 1; i >= 0; i--) {
        cout << char(num[i] + '0');
    }
    cout << '\n';
    return;
}

vector <char> mul (vector <char>& num, int p) {
    vector <char> res;
    int pr = 0, cur;
    for(int i = 0; i < num.size(); i++) {
        cur = num[i] * p + pr;
        pr = cur / 10;
        res.push_back(cur - 10 * pr);
    }
    while(pr != 0) {
        cur = pr;
        pr /= 10;
        res.push_back(cur - 10 * pr);
    }
    return res;
}

vector <char> sum (vector <char>& n1, vector <char>& n2) {
    vector <char> res;
    if(n1.size() < n2.size()) swap(n1, n2);
    int pr = 0, cur;
    for(int i = 0; i < n1.size(); i++) {
        if(i < n2.size()) cur = n1[i] + n2[i] + pr;
        else cur = n1[i] + pr;
        if(cur >= 10) {
            res.push_back(cur - 10);
            pr = 1;
        } else {
            res.push_back(cur);
            pr = 0;
        }
    }
    if(pr > 0) res.push_back(pr);
    return res;
}

int main () {
    string s;
    int p;
    cin >> s >> p;
    vector <char> n10, stp;
    stp.push_back(1);
    for(int i = s.size() - 1; i >= 0; i--) {
        vector <char> hi = mul(stp, s[i] - '0');
        n10 = sum(n10, hi);
        stp = mul(stp, p);
    }
    print(n10);
    return 0;
}
