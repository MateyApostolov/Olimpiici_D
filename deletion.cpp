#include <bits/stdc++.h>
using namespace std;

int main () {
    long long n, br2 = 0, br20 = 0, br201 = 0, br2014 = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        vector <int> nc;
        int h = i;
        while(h > 0) {
            nc.push_back(h % 10);
            h /= 10;
        }
        for(int i = nc.size() - 1; i >= 0; i--) {
            if(nc[i] == 2) br2++;
            if(nc[i] == 0) br20 += br2;
            if(nc[i] == 1) br201 += br20;
            if(nc[i] == 4) br2014 += br201;
        }
    }
    cout << br2014;
    return 0;
}
