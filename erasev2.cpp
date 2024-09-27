#include <bits/stdc++.h>
using namespace std;

const int maxk = 1000;

int main () {
    int n, q, qc;
    cin >> n >> q;
    vector <vector <int>> nc(maxk);
    for(int i = 1; i <= n; i++) {
        nc[i / maxk].push_back(i);
    }
    for(int i = 0; i < q; i++) {
        cin >> qc;
        nc[qc / maxk].erase(nc[qc / maxk].begin() + qc);
    }
    for(int i = 0; i < )

    return 0;
}
