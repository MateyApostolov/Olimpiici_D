#include <bits/stdc++.h>
using namespace std;

const int maxc = pow(10, 7) + 1;
int brdel[maxc], num[maxc];

void eratosten () {
    for(long long d = 2; d < maxc; d++)  {
        for(long long h = d; h < maxc; h += d)  {
            brdel[d] += num[h];
        }
    }
    return;
}

int main () {
    int n, k, nc, maxn = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++)  {
        cin >> nc;
        maxn = max(maxn, nc);
        num[nc]++;
    }
    eratosten();
    brdel[1] = k;
    for(int i = maxn; i >= 1; i--) {
        if(brdel[i] == k) {
            cout << i;
            return 0;
        }
    }

    return 0;
}
