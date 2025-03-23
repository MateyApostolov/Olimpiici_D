#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, q, qc;
    cin >> n >> q;
    int nc[n];
    for(int i = 0; i < n; i++) cin >> nc[i];
    sort(nc, nc + n);
    for(int i = 0; i < q; i++) {
        cin >> qc;
        int b = 0, e = n - 1, mid, ans = -1, breq = 1;
        while(b <= e) {
            mid = (b + e) / 2;
            if(qc >= nc[mid]) {
                b = mid + 1;
                ans = mid;
            }
            else {
                e = mid - 1;
            }
        }
        if(qc != nc[ans]) {
            cout << ans + 1 << ' ' << 0 << ' ' << n - ans - 1;
            continue;
        }
        while(ans - 1 >= 0 && nc[ans - 1] == qc) {
            ans--;
            breq++;
        }
        cout << ans << ' ' << breq << ' ' << n - ans - breq << '\n';
    }

    return 0;
}


