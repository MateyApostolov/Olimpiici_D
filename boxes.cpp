#include <bits/stdc++.h>
using namespace std;

const int maxc = pow(10, 3) + 1;
int brc[maxc];

int main () {
    int n, nc, s = 0, brb = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> nc;
        brc[nc]++;
    }
    for(int i = 1000; i >= 1; i--) {
        if(brb < brc[i]) {
            s += (brc[i] - brb) * i;
            brb += brc[i] - brb;
        }
    }
    cout << s;
    return 0;
}
