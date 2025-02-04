#include <bits/stdc++.h>
using namespace std;

const int maxc = pow(10, 5) + 1;
bool ist[maxc];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, hi, ri, brt = 0;
    char op;
    cin >> n >> m;
    int nc[n];
    nc[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> nc[i];
        if(nc[i] < nc[i - 1]) {
            ist[nc[i]] = true;
            brt++;
        }
    }
    for(int i = 0; i < m; i++) {
        cin >> op;
        if(op == '!') {
            cin >> hi >> ri;
            nc[hi] = ri;
            if(nc[hi - 1] > nc[hi]) {
                if(!ist[hi]) brt++;
                ist[hi] = true;
            } else {
                if(ist[hi]) brt--;
                ist[hi] = false;
            }
            if(hi + 1 > n) continue;
            if(nc[hi] > nc[hi + 1]) {
                if(!ist[hi + 1]) brt++;
                ist[hi + 1] = true;
            } else {
                if(ist[hi + 1]) brt--;
                ist[hi + 1] = false;
            }
        }
        if(op == '?') {
            if(brt == 0) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}
