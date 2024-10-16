#include <bits/stdc++.h>
using namespace std;

long long mc[10][10];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, nc, brp = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> nc;
        int h = 0;
        while(nc > 0) {
            mc[h][nc % 10]++;
            h++;
            nc /= 10;
        }
    }
    for(int i1 = 0; i1 < 10; i1++) {
        for(int i2 = 0; i2 < 10; i2++) {
            brp += (mc[i1][i2] * (mc[i1][i2] - 1)) / 2;
        }
    }
    cout << brp;
    return 0;
}
