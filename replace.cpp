#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, k, r = -1, maxr = 0;
    cin >> n >> k;
    int nc[n];
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
    }
    for(int i = 1; i < 31; i++) {
        int brd = 0;
        int l;
        while(r < n && nc[r] != i && brd < k) {
            brd++;
            r++;
        }
        while(l < r && nc[l] == i) {
            l++;
        }
        maxr = max(maxr, r - l + 1);
    }
    cout << maxr;
    return 0;
}
