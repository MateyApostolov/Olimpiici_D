#include <bits/stdc++.h>
using namespace std;

const int maxm = pow(10, 5) + 1;
long long nc[maxm], m, n;
bool bs (long long mid) {
    long long sum = 0, brp = 1;
    for(int i = 1; i <= m; i++) {
        sum += nc[i];
        if(sum > mid) {
            sum = nc[i];
            brp++;
            if(brp > n) return false;
        }
    }
    return true;
}

int main () {
    long long l = 0, r = 0, mid;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> nc[i];
        r += nc[i];
        l = max(l, nc[i]);
    }
    while(l <= r) {
        mid = (l + r) / 2;
        if(bs(mid)) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << l;

    return 0;
}
