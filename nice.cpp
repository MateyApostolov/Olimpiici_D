#include <bits/stdc++.h>
using namespace std;

bool c[1000000];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, br = 0;
    cin >> n;
    int nc[n];
    for(int i = 0; i < n; i++) cin >> nc[i];
    for(int i1 = 0; i1 < n; i1++) {
        for(int i2 = 0; i2 < i1; i2++) {
            if(c[nc[i1] - nc[i2] + 500000]) {
                br++;
                break;
            }
        }
        for(int i3 = 0; i3 <= i1; i3++) c[nc[i1] + nc[i3] + 500000] = true;
    }
    cout << br;

    return 0;
}
