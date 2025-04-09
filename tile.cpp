#include <bits/stdc++.h>
using namespace std;

long long a, k, b, m, x, l, r = pow(10, 18) / 2, mid;

bool ok (long long num) {
    long long sumd = a * (num - (num / k)) + b * (num - (num / m));
    if(sumd >= x) return false;
    else return true;
}

int main () {
    cin >> a >> k >> b >> m >> x;
    while(l <= r) {
        mid = (l + r) / 2;
        if(ok(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << l;
    return 0;
}
