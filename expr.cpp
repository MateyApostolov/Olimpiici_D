#include <bits/stdc++.h>
using namespace std;

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

int main () {
    string n1, n2, res;
    cin >> n1 >> n2;
    res = raz(n1, n2);
    cout << res;

    return 0;
}
