#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, pr = 1, popr = 1, nc;
    cin >> n;
    string s = "11";
    while(s.size() < n) {
        nc = pr + popr;
        s += to_string(nc);
        popr = pr;
        pr = nc;
    }
    cout << s[n - 1];
    return 0;
}
