#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, k, sum = 0;
    cin >> n >> k;
    int nc[n];
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
        sum += nc[i];
    }
    sort(nc, nc + n);
    reverse(nc, nc + n);
    for(int i = k - 1; i < n; i += k) {
        sum -= nc[i];
    }
    cout << sum;
    return 0;
}
