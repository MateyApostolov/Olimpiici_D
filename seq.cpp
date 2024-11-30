#include <bits/stdc++.h>
using namespace std;

int brx;

vector <char> mul (vector <char> num, int x) {
    vector <char> res;
    for(int i = 0; i < num.size() + brx; i++) {
        res.push_back(0);
    }
    int pr, c, hi = 0, pos;
    while(x > 0) {
        pos = hi;
        c = x % 10;
        x /= 10;
        pr = 0;
        for(int i = num.size() - 1; i >= 0; i--) {
            int hnum = c * num[i] + res[pos] + pr;
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
    reverse(res.begin(), res.end());
    return res;
}

int main () {
    int x, n, h;
    cin >> x >> n;
    h = x;
    while(h > 0) {
        h /= 10;
        brx++;
    }
    vector <char> num, red;
    num.push_back(1);
    red.push_back(1);
    do {
        for(int i = 0; i < num.size(); i++) {
            red.push_back(num[i]);
        }
        num = mul(num, x);
    } while(red.size() < n);
    cout << int(red[n]);
    return 0;
}
