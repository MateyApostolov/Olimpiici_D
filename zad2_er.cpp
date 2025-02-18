#include <bits/stdc++.h>
using namespace std;

const int maxc = pow(10, 6) + 1;
int br_prime[maxc], pref[maxc];

void eratosten () {
    for(int d = 2; d <= maxc; d++) {
        if(br_prime[d] != 0) continue;
        for(int h = d; h <= maxc; h += d) {
            br_prime[h]++;
        }
    }
    return;
}

int main () {
    int n, l, r;
    cin >> n;
    eratosten();
    for(int i = 1; i < maxc; i++) {
        pref[i] = pref[i - 1];
        if(br_prime[i] == 3) pref[i]++;
    }
    for(int i = 0; i < n; i++) {
        cin >> l >> r;
        cout << pref[r] - pref[l - 1] << '\n';
    }

    return 0;
}
