#include <bits/stdc++.h>
using namespace std;

int brs[10];

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
    if(res.size() == hi) {
        res.clear();
        res.push_back('0');
        return res;
    }
    return res.substr(hi, res.size() - hi);
}

int main () {
    string s, nms = "", ngs = "";
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        brs[s[i] - '0']++;
    }
    sort(s.begin(), s.end());
    nms = s.substr(brs[0], s.size() - brs[0]);
    reverse(s.begin(), s.end());
    ngs = s;
    cout << ngs << ' ' << nms << '\n';
    cout << raz(ngs, nms);
    return 0;
}
