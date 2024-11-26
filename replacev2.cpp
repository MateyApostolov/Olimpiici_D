#include <bits/stdc++.h>
using namespace std;

int brcr[101];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, r = -1, maxr = 0, maxc = 0;
    cin >> n >> k;
    int nc[n];
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
    }
    for(int l = 0; l < n; l++) {
        while(r + 1 < n && r - l + 1 <= k + maxc) {
            r++;
            brcr[nc[r]]++;
            maxc = 0;
            for(int i = 0; i < 100; i++) {
                maxc = max(maxc, brcr[i]);
            }
        }
        maxr = max(maxr, r - l);
        brcr[l]--;
        maxc = 0;
        for(int i = 0; i < 100; i++) {
            maxc = max(maxc, brcr[i]);
        }
    }
    cout << maxr;
    return 0;
}
