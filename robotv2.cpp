#include <bits/stdc++.h>
using namespace std;

const int maxcr = 21, maxc = 2 * maxcr + 1;



int main () {
    int k, j, i;
    cin >> k >> j >> i;
    long long d2[maxc][maxc] = {{}};
    d2[maxcr][maxcr] = 1;
    if((abs(i) + abs(j)) % 2 != k % 2) {
        cout << 0;
        return 0;
    }
    for(int i = 0; i < k; i++) {
        long long h[maxc][maxc] = {{}};
        for(int r = 1; r < maxc - 1; r++) {
            for(int c = 1; c < maxc - 1; c++) {
                h[r][c] = d2[r - 1][c] + d2[r + 1][c] + d2[r][c + 1] + d2[r][c - 1];

            }
        }
        for(int r = 0; r < maxc; r++) {
            for(int c = 0; c < maxc; c++) {
                d2[r][c] = h[r][c];
            }
        }
    }
    cout << d2[j + maxcr][i + maxcr];
    return 0;
}
