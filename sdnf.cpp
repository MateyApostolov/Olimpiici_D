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
    long long n, sum = 0;
    cin >> n;
    vector <char> num;
    num.push_back(1);
    for(int i = 2; i <= n; i++) {
        vector <char> hnum;
        int hi = i;
        while(hi > 0) {
            hnum.push_back(hi % 10);
            hi /= 10;
        }
        reverse(hnum.begin(), hnum.end());
        num = mul(num, hnum);
    }
    for(int i = 0; i < num.size(); i++) {
        sum += num[i];
    }
    cout << sum;
    return 0;
}
