#include <bits/stdc++.h>
using namespace std;

int main () {
    long long n, k, l = 0, r = 0, muls = 0, sum = 0, brt = 0;
    cin >> n >> k;
    long long nc[n];
    for(int i = 0; i < n; i++) cin >> nc[i];
    sum = nc[0];
    while(true) {
        r++;
        muls += nc[r] * sum;
        sum += nc[r];
        while(l < r && muls >= k) {
            brt++;
            muls -= nc[l] * sum;
            sum -= nc[l];
            l++;
        }
        if(l == n - 2) break;
    }
    cout << brt;

    return 0;
}
