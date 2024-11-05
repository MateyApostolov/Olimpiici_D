#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, br = 0;
    cin >> n;
    int nc[n];
    map <int, bool> c;
    for(int i = 0; i < n; i++) cin >> nc[i];
    for(int i1 = 0; i1 < n; i1++) {
        if(c[nc[i1]]) br++;
        for(int i2 = 0; i2 < i1; i2++) {
            for(int i3 = 0; i3 < i1; i3++) {
                c[nc[i1] + nc[i2] + nc[i3]] = true;
                ///cout << i1 << ' ' << i2 << ' ' << i3 << ' ' << br << '\n';
            }
        }
    }
    cout << br;

    return 0;
}
