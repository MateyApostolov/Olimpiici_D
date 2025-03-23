#include <bits/stdc++.h>
using namespace std;

const int maxc = 5 * pow(10, 5);
int brg1[maxc], brg2[maxc];

int main () {
    long long n, m, sums = 0, sumb = 0;
    cin >> n >> m;
    long long nc[n], mc[m], mt[n][m];
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> mc[i];
    }
    for(int r = 0; r < m; r++) {
        for(int c = 0; c < n; c++) {
            mt[r][c] = min(nc[r], mc[c]);
            sumb += min(nc[r], mc[c]);
        }
    }
    for(int i = 0; i < m; i++) {
        brg1[mc[i]]++;
        if(i >= n) continue;
        brg2[nc[i]]++;
    }
    for(int i = 0; i < maxc; i++) {
        sums += max(brg1[i], brg2[i]);
    }
    cout << sums << ' ' << sumb;
    return 0;
}
