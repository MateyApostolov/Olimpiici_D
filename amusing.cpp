#include <bits/stdc++.h>
using namespace std;

const int maxn = pow(10, 7);
bool zdr[maxn];

void eratosten () {
    for(long long d = 2; d <= maxn; d++) {
        if(zdr[d]) continue;
        for(long long h = d * d; h <= maxn; h += d) {
            zdr[h] = true;
        }
    }
    return;
}

int main () {
    long long l, r, brc = 0;
    cin >> l >> r;
    vector <long long> prime;
    eratosten();
    for(int i = 2; i <= maxn; i++) {
        if(!zdr[i]) prime.push_back(i);
    }
    for(int i = 0; i < prime.size(); i++) {
        int hnum = prime[i];
        for(int d = 2; d <= 50; d++) {
            hnum *= prime[i];
            if(hnum >= l && hnum <= r && !zdr[d + 1]) brc++;
            if(hnum > r) break;
        }
    }
    cout << brc;
    return 0;
}
