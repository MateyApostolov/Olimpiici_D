#include <bits/stdc++.h>
using namespace std;

vector <char> mul (vector <char> num1, vector <char> num2) {
    vector <char> res;
    for(int i = 0; i < num1.size() + num2.size(); i++) {
        res.push_back(0);
    }
    int pr, c, hi = 0, pos;
    for(int ci = num2.size() - 1; ci >= 0; ci--) {
        pos = hi;
        c = num2[ci];
        pr = 0;
        for(int i = num1.size() - 1; i >= 0; i--) {
            int hnum = c * num1[i] + res[pos] + pr;
            pr = hnum / 10;
            res[pos] = hnum % 10;
            pos++;
        }
        if(pr != 0) {
            res[pos] = pr;
        }
        hi++;
    }
    while(!res.empty() && res[res.size() - 1] == 0) {
        res.pop_back();
    }
    reverse(res.begin(), res.end());
    if(res.size() == 0) res.push_back(0);
    return res;
}


int main () {
    string num1, num2;
    cin >> num1 >> num2;
    vector <char> s, rmax;
    rmax.push_back(0);
    for(int i = 0; i < num1.size(); i++) {
        s.push_back(num1[i] - '0');
    }
    for(int i = 0; i < num2.size(); i++) {
        s.push_back(num2[i] - '0');
    }
    for(int i1 = 0; i1 < s.size() - 1; i1++) {
        for(int i2 = i1 + 1; i2 < s.size(); i2++) {
            vector <char> s1, s2, r;
            for(int i = i1; i < i2; i++) {
                s1.push_back(s[i]);
            }
            for(int i = i2; i < s.size(); i++) {
                s2.push_back(s[i]);
            }
            for(int i = 0; i < i1; i++) {
                s2.push_back(s[i]);
            }
            r = mul(s1, s2);
            if(r.size() > rmax.size()) rmax = r;
            if(r.size() == rmax.size()) {
                for(int i = 0; i < r.size(); i++) {
                    if(rmax[i] > r[i]) break;
                    if(r[i] > rmax[i]) {
                        rmax = r;
                        break;
                    }
                }
            }
        }
    }
    if (rmax.size() == 0) {
        cout << '0';
        return 0;
    }
    for(int i = 0; i < rmax.size(); i++) {
        cout << char(rmax[i] + '0');
    }
    return 0;
}
