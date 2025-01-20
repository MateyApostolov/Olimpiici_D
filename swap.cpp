#include <bits/stdc++.h>
using namespace  std;

int main () {
    int n, br = 0;
    cin >> n;
    int nc[n], pos[n];
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
        pos[nc[i]] = i;
    }
    for(int i = 0; i < n; i++) {
        if(nc[i] == i) continue;
        pos[nc[i]] = pos[i];
        swap(nc[i], nc[pos[i]]);
        br++;
 ///       pos[i] = i;
    }
    cout << br;
    return 0;
}
