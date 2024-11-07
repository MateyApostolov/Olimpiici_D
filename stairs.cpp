#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, br = 1, maxbr = 0;
    cin >> n >> k;
    int nc[n];
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
    }
    sort(nc, nc + n);
    for(int i = 1; i < n; i++) {
        if(nc[i] == nc[i - 1]) continue;
        if(nc[i] - nc[i - 1] <= k) {
            br++;
        } else {
            maxbr = max(maxbr, br);
            br = 1;
        }
    }
    maxbr = max(maxbr, br);
    cout << maxbr;
    return 0;
}
