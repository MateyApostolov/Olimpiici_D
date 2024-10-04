#include <bits/stdc++.h>
using namespace std;

const int maxc = pow(10,5);
int brc1[maxc];

int main () {
    int n, x, nc, br = 0;
    cin >> n >> x;
    int nc1, nc2;
    for(int i = 0; i < n; i++) {
        cin >> nc1;
        brc1[nc1]++;
    }
    for(int i = 0; i < n; i++) {
        cin >> nc2;
        if(x - nc2 > 0) {
            br += brc1[x - nc2];
        }
    }
    cout << br;
    return 0;
}

