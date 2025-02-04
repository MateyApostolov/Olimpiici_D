#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    int brb = 0;
    for(int i1 = 0; i1 < s.size(); i1++) {
        if(s[i1] ==  ')') continue;
        stack <int> sk;
        for(int i2 = i1; i2 < s.size(); i2++) {
            if(s[i2] == '(') sk.push(1);
            else if(!sk.empty())  sk.pop();
            else break;
            if(sk.empty()) brb++;
        }
    }
    cout << brb;

    return 0;
}
