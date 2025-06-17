#include <bits/stdc++.h>
using namespace std;

const int maxk = 51;
int upk[maxk][maxk];

int main () {
    int k, n;
    cin >> k >> n;
    for(int x = 1; x <= n; x++) {
        for(int y = 1; y <= k; y++) {
            if(x == 1) upk[x][y] = y;
            else upk[x][y] = upk[x][y - 1] + upk[x - 1][y - 1];
        }
    }
    cout << upk[n][k];
    return 0;
}
