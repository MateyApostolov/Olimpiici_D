#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, k, l, r, mid;
    cin >> n >> k;
    long long r1[n], r2[n];
    for(int i = 0; i < n; i++) cin >> r1[i];
    for(int i = 0; i < n; i++) cin >> r2[i];
    sort(r1, r1 + n);
    sort(r2, r2 + n);
    l = r1[0] + r2[0];
    r = r1[n - 1] + r2[n - 1];
    while(l <= r) {
        mid = (l + r) / 2;
        long long brs = 0, x = n - 1;
        for(int i = 0; i < n; i++) {
            while(x >= 0 && r1[i] + r2[x] > mid) x--;
            brs += x + 1;
        }
        if(brs < k) l = mid + 1;
        else r = mid - 1;
    }
    cout << l;
    return 0;
}
