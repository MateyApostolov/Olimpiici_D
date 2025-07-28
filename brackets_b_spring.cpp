#include <bits/stdc++.h>
using namespace std;

const int mod = 1001027;
const int maxn = 1000;
int n, k, kc;
bool mp[2 * maxn];
int mm[maxn][maxn];

int gen (int op, int cl) {
    if(op + cl == 2 * n) return 1;
    if(n < op || n < cl) return 0;
    if(mm[op][cl] != 0) return mm[op][cl];
    if(mp[op + cl + 1]) return mm[op][cl] = gen(op + 1, cl);
    else {
        int v1 = 0, v2 = 0;
        if(op < n) v1 = gen(op + 1, cl);
        if(op > cl) v2 = gen(op, cl + 1);
        mm[op][cl] = (v1 + v2) % mod;
        return mm[op][cl];
    }
}

int main () {
    cin >> n >> k;
    for(int i = 0; i < k; i++) {
        cin >> kc;
        mp[kc] = true;
    }
    cout << gen(0, 0);
    return 0;
}
