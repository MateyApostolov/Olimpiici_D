#include <bits/stdc++.h>
using namespace std;

int main () {
    long long n, k, r = 0, muls = 0, sum, brt = 0;
    cin >> n >> k;
    long long nc[n];
    for(int i = 0; i < n; i++) cin >> nc[i];
    sum = nc[0];
    for(int i = 0; i < n;) {
        while(r + 1 < n && muls < k) {
            r++;
            muls += nc[r] * sum;
            sum += nc[r];
        }
        if(r != n - 1 || muls >= k) brt += n - r;
        sum -= nc[i];
        muls -= sum * nc[i];
        i++;
    }
    cout << brt;

    return 0;
}


