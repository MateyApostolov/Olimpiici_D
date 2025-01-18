#include <bits/stdc++.h>
using namespace std;

int main () {
    long long n, k, m = 1, res = 0, brs = 0;
    cin >> n >> k;
    while(m < n) {
        res += 2 * m - 1;
        m++;
    }
    if(k == 1) {
        res += n;
        cout << res;
        return 0;
    }
    res += 2 * m - 1;
    m++;
    k--;
    while(k > 2) {
        res += 2 * m - 1;
        m++;
        k -= 2;
    }
    if(k == 1) res += n;
    if(k == 2) res += 2 * m - n;
    cout << res;
    return 0;
}
