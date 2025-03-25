#include <bits/stdc++.h>
using namespace std;

int main () {
    unsigned long long n, l = 0, r, mid;
    cin >> n;
    r = n / 2;
    while(l <= r) {
        mid = (r + l) / 2;
        if(mid * mid == n) {
            l = mid;
            break;
        }
        if(mid * mid < n) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    if(l * l == n) cout << l << '\n';
    else cout << 0 << '\n';
    return 0;
}
