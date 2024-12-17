#include <bits/stdc++.h>
using namespace std;

vector <char> mul (vector <char>& num1, vector <char>& num2) {
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
    while(res[res.size() - 1] == 0) {
        res.pop_back();
    }
    return res;
}

int main () {
    int n;
    cin >> n;
    vector <char> s, r;
    for(int i = 0; i < n; i++) {
        s.push_back(1);
    }
    r = mul(s, s);
    for(int i = r.size() - 1; i >= 0; i--) {
        cout << char(r[i] + '0');
    }

    return 0;
}
