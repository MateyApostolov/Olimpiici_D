#include <bits/stdc++.h>
using namespace std;

int br_ewk (int a, int b) {
    int c, br = 0;
    if (b > a) swap(a, b);
    while (b>0) {
        c = a % b;
        a = b;
        b = c;
        br++;
    }
    return br;
}

int main () {
    map <int, pair<int, int>> mp;
    for(int a = 1; a <= 1000; a++) {
        for(int b = a + 1; b <= 1000; b++) {
            int br = br_ewk(a, b);
            if(mp.find(br) == mp.end()) mp[br] = {a, b};
            else if(a < mp[br].first) mp[br] = {a, b};
        }
    }
    for(auto x : mp) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << '\n';
    }

    return 0;
}
