#include <bits/stdc++.h>
using namespace std;

const int maxk = 1000;

int main () {
    int n, q, qc;
    cin >> n >> q;
    vector <int> nc[maxk];
    for(int i = 1; i <= n; i++) {
        nc[i / maxk].push_back(i);
    }
    for(int i = 0; i < q; i++) {
        cin >> qc;
        int h = 0;
        while(h < maxk && qc > nc[h].size()) {
            cout << h << ' ' << qc << '\n';
            qc -= nc[h].size();
            h++;
        }
        nc[h].erase(nc[h].begin() + qc - 1);
    }
    for(int i1 = 0; i1 < maxk; i1++) {
        for(int i2 = 0; i2 < nc[i1].size(); i2++) {
            cout << nc[i1][i2] << ' ';
        }
    }

    return 0;
}
