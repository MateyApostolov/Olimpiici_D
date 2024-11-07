#include <bits/stdc++.h>
using namespace std;

int main () {
    long long n, k, h, brc = 0;
    cin >> n >> k;
    h = n;
    vector <long long> nc;
    while(h > 0) {
        h /= 10;
        brc++;
    }
    if(k == 0) {
        for(int i1 = 1; i1 < 10; i1++) {
            long long num = 0;
            for(int i2 = 0; i2 < brc; i2++) {
                num *= 10;
                num += i1;
            }
            nc.push_back(num);
        }
    } else {
        for(int i1 = 0; i1 < 10; i1++) {
            for(int i2 = 0; i2 < 10; i2++) {
                for(int i3 = 0; i3 < brc; i3++) {
                    long long num = 0;
                    for(int i4 = 0; i4 < i3; i4++) {
                        num *= 10;
                        num += i2;
                    }
                    num *= 10;
                    num += i1;
                    for(int i4 = i3 + 1; i4 < brc; i4++) {
                        num *= 10;
                        num += i2;
                    }
                    nc.push_back(num);
                }
            }
        }
    }
    sort(nc.begin(), nc.end());
    int hi = 0;
    while(nc[hi] < n) {
        hi++;
    }
    cout << nc[hi];
    return 0;
}
