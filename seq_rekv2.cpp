#include <bits/stdc++.h>
using namespace std;

const int maxk = 51;
long long mp[maxk][maxk];
int k, n, br;

long long Fm (int k, int n) {
    if(mp[k][n] != -1) return mp[k][n];
    if(n == 1) return k;
    if(n == k) return 1;
    if(n > k) return 0;
    return Fm(k - 1, n - 1) + Fm(k - 1, n);
}

int main () {
    for(int j = 0; j < maxk; j++) {
        for(int i = 0; i < maxk; i++) {
            mp[j][i] = -1;
        }
    }
    cin >> k >> n;
    cout << Fm(k, n);
    return 0;
}
