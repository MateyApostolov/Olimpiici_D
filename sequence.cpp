#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, nc, pr, br = 0, ngbr = 0;
    cin >> n >> k;
    cin >> nc;
    pr = nc;
    bool ispr, isin = true;
    if(pr == 0) {
        br++;
        ispr = true;
    } else {
        ispr = false;
        isin = false;
    }
    for(int i = 1; i < n; i++) {
        cin >> nc;
        if(nc == pr + 1 && ispr) {
            br++;
        } else {
            ispr = false;
            ngbr = max(ngbr, br);
            br = 0;
            if(nc == 0) {
                br = 1;
                ispr = true;
            } else  {
                isin = false;
            }
        }
        pr = nc;
    }
    if(ispr) ngbr = max(ngbr, br);
    if(ngbr > k) isin = false;
    if(!isin) {
        cout << "No " << ngbr;
    } else {
        cout << "Yes " << ngbr;
    }
    return 0;
}
