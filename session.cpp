#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, k, nc, pr, brs, br = 0;
    cin >> n >> k;
    cin >> pr;
    if(pr < k) {
        brs = 0;
    } else {
        brs = 1;
    }
    for(int i = 1; i < n; i++) {
        cin >> nc;
        if(nc <= pr && nc >= k) {
            brs++;
        } else {
            br += (brs * (1 + brs)) / 2;
            if(nc < k) {
                brs = 0;
            } else {
                brs = 1;
            }
        }
        pr = nc;
    }
    br += (brs * (1 + brs)) / 2;
    cout << br;
    return 0;
}
