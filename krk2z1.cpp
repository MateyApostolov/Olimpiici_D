#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, nc, pr, br = 1, ngbr = 0;
    cin >> n;
    cin >> nc;
    pr = nc;
    for(int i = 1; i < n; i++) {
        cin >> nc;
        if(nc > pr) {
            br++;
        } else {
            ngbr = max(br, ngbr);
            br = 1;
        }
        pr = nc;
    }
    cout << ngbr;
    return 0;
}
