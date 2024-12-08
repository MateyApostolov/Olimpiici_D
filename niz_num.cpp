#include <bits/stdc++.h>
using namespace std;

const string s;

long long toNumber(const string& s) {
    long long num = 0, hi = 0;
    while(hi < s.size()) {
        num *= 10;
        num += s[hi];
        hi++;
    }
    return num;
}

int main () {
    long long num;
    cin >> s;
    num = toNumber(s);
    cout << num;
    return 0;
}
