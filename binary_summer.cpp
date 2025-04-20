#include <bits/stdc++.h>
using namespace std;

int main () {
    string s;
    cin >> s;
    int k, brp0 = 0, r = 0, br0 = 0;
    cin >> k;
    for(int i = 0; i < s.size(); ) {
        while(r < s.size() && br0 <= k) {
            if(s[r] == '0') br0++;
            if(br0 == k) break;
            r++;
        }
        if(br0 == k) brp0++;
        if(s[i] == '0') br0--;
        i++;
    }
    cout << brp0;
    return 0;
}
