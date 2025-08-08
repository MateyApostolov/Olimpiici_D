#include <bits/stdc++.h>
using namespace std;

const int maxk = pow(10, 5) + 1;
int n, k;
int kc[maxk];

long long ok (long long num) {
    long long br = 0;
    for(int i = 0; i < k; i++) {
        br += num / kc[i];
    }
    if(br >= n) return true;
    return false;
}

int main () {
    cin >> n >> k;
    for(int i = 0; i < k; i++) cin >> kc[i];
    long long l = 0, r = pow(10, 10), m;
    while(l <= r) {
        m = l + (r - l) / 2;
        if(ok(m)) r = m - 1;
        else l = m + 1;
    }
    cout << l;
    return 0;
}
