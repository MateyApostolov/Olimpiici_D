#include <bits/stdc++.h>
using namespace std;

const int maxc = 100000;
int brc1[maxc], brc2[maxc];

int main () {
    int n, x, nc, br = 0;
    cin >> n >> x;
    int nc1[n], nc2[n];
    for(int i = 0; i < n; i++) {
        cin >> nc1[i];
        brc1[nc1[i]]++;
    }
    for(int i = 0; i < n; i++) {
        cin >> nc2[i];
        brc2[nc2[i]]++;
    }
    for(int i = 0; i < n; i++) {
        if(brc1[nc1[i]] > 0) {
            br += brc1[nc1[i]] * brc2[x - nc1[i]];
        }
    }
    cout << br;
    return 0;
}

