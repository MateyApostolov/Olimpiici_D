#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, maxr = 0;
    cin >> n >> k;
    int nc[n];
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
    }
    for(int i = 0; i < 30; i++) {
        int brd = 0;
        int r = -1;
        for(int l = 0; l < n; l++) {
            while(r + 1 < n && r - l + 1 <= k + brd) {
                r++;
                if(nc[r] == i) {
                    brd++;
                }
            }
            if(r - l + 1 <= k + brd) maxr = max(maxr, r - l + 1);
            else {
                maxr = max(maxr, r - l);
            }
            if(nc[l] == i) {
                brd--;
            }
        }
    }
    cout << maxr;
    return 0;
}
