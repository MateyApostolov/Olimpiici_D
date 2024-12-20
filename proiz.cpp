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
    vector <char> s1, s2, res;
    string n1, n2;
    cin >> n1 >> n2;
    for(int i = 0; i < n1.size(); i++) {
        s1.push_back(n1[i] - '0');
    }
    for(int i = 0; i < n2.size(); i++) {
        s2.push_back(n2[i] - '0');
    }
    res = mul(s1, s2);
    for(int i = 0; i < res.size(); i++) {
        cout << char(res[i] + '0');
    }

    return 0;
}
