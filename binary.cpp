#include <bits/stdc++.h>
using namespace std;

string s;

int br1 (int l) {
    int br = 0;
    while(l - 1 >= 0 && s[l - 1] == '1') {
        br++;
        l--;
    }
    return br;
}

int br2 (int r) {
    int br = 0;
    while(r + 1 < s.size() && s[r + 1] == '1') {
        br++;
        r++;
    }
    return br;
}

int main () {
    int k, r = -1, ans = 0, br0 = 0;
    cin >> s >> k;
    for(int l = 0; l < s.size(); l++) {
        while(r + 1 < s.size() && br0 < k) {
            r++;
            if(s[r] == '0') br0++;
        }
        while(l < s.size() && s[l] != '0') l++;
        if(br0 == k) ans += (br1(l) + 1) * (br2(r) + 1);
        if(s[l] == '0') br0--;
    }
    cout << ans;
    return 0;
}
