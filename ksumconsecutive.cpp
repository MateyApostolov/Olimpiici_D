#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, k, ngsum = 0, r = -1, sum = 0;
    cin >> n >> k;
    int nc[n];
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
    }
    for(int l = 0; l < n; l++) {
        while(r + 1 < n && sum + nc[r + 1] <= k) {
            r++;
            sum += nc[r];
        }
        ngsum = max(ngsum, sum);
        sum -= nc[l];
    }
    if(ngsum == 0) {
        cout << -1;
        return 0;
    }
    cout << ngsum;
    return 0;
}
