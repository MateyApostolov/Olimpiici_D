#include <bits/stdc++.h>
using namespace std;

const int maxc = 2  * pow(10,  5);
int lvl[maxc];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    int brb = 0, hi = 0, pr;
    stack <int> sk;
    for(int i1 = 0; i1 < s.size(); i1++) {
        if(s[i1] == '(') {
            sk.push(hi);
            pr = hi;
            hi++;
        } else if(!sk.empty()) {
            if(sk.top() == hi)  lvl[hi]++;
            else {
                lvl[sk.top()]++;
                lvl[hi] = 0;
            }
            brb += lvl[sk.top()];
            hi--;
            pr = sk.top();
            sk.pop();
        } else {
            lvl[0] = 0;
        }
    }
    cout << brb;

    return 0;
}
