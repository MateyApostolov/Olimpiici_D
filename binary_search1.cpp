#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, q, qc;
    cin >> n >> q;
    int nc[n];
    for(int i = 0; i < n; i++) cin >> nc[i];
    for(int i = 0; i < q; i++) {
        cin >> qc;
        int b = 1, e = n, mid;
        bool t = false;
        while(b <= e) {
            mid = (b + e) / 2;
            if(qc > nc[mid - 1]) b = mid + 1;
            else if(qc < nc[mid - 1]) e = mid - 1;
            if(qc == nc[mid - 1]) {
                cout << "yes\n";
                t = true;
                break;
            }
        }
        if(!t) cout << "no\n";
    }

    return 0;
}
