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

string raz (string n1, string n2) {
    string res;
    int pr = 0, i1 = n1.size() - 1, i2 = n2.size() - 1, hi = 0;
    while(i1 >= 0) {
        int sg;
        if(i2 < 0) {
            if(n1[i1] - '0' == 0) {
                sg = (n1[i1] - '0' + 10 - pr) % 10;
                pr = 1;
            } else {
                sg = n1[i1] - '0' - pr;
                pr = 0;
            }
        } else {
            if(n1[i1] < n2[i2] + pr) {
                sg = n1[i1] + 10 - n2[i2] - pr;
                pr = 1;
            } else {
                sg = n1[i1] - n2[i2] - pr;
                pr = 0;
            }
        }
        res = char(sg + '0') + res;
        i1--;
        i2--;
    }
    while(res[hi] == '0') {
        hi++;
    }
    return res.substr(hi, res.size() - hi);
}

string sbor (string n1, string n2) {
    string res;
    int pr = 0, i1 = n1.size() - 1, i2 = n2.size() - 1;
    while(i1 >= 0 || i2 >= 0) {
        int sg;
        if(i1 < 0) {
            sg = 0 + n2[i2] - '0' + pr;
        } else if(i2 < 0) {
            sg = n1[i1] - '0' + 0 + pr;
        } else {
            sg = n1[i1] - '0' + n2[i2] - '0' + pr;
        }
        res = char(sg % 10 + '0') + res;
        pr = sg / 10;
        i1--;
        i2--;
    }
    if(pr != 0) res = char(pr + '0') + res;
    return res;
}

int main () {
    int n;
    vector <char> nc, dw;
    string m;
    nc.push_back(1);
    dw.push_back(2);
    cin >> n >> m;
    while(n > 0) {
        n--;
        nc = mul(nc, dw);
    }
    string num;
    for(int i = 0; i < nc.size(); i++) {
        num += nc[i] + '0';
    }
    if(m[0] == '-') {
        m = m.substr(1, m.size() - 1);
        cout << sbor(num, m);
    } else {
        cout << raz(num, m);
    }
    return 0;
}
