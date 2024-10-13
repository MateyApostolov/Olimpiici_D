#include <bits/stdc++.h>
using namespace std;

const int maxc = 1000;
int brc[maxc];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, nc;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> nc;
        brc[nc]++;
    }
    for(int i = 0; i < maxc; i++) {
        while(brc[i] > 0) {
            cout << i << ' ';
            brc[i]--;
        }
    }

    return 0;
}
