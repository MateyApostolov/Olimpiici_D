#include <bits/stdc++.h>
using namespace std;

const int maxn = 30002;
long long pref1[maxn], pref2[maxn];

int main () {
    int n, m, r;
    cin >> n >> m >> r;
    pref1[1] = 1;
    pref1[0] = 1;
    for(int i = 2; i <= n; i++) {
        pref1[i] = (pref1[i - 1] * i) % m;
    }
    pref2[n] = n % m;
    pref2[n + 1] = 1;
    for(int i = n - 1; i > 0; i--) {
        pref2[i] = (pref2[i + 1] * i) % m;
    }
    for(int i = 1; i <= n; i++) {
        if((pref1[i - 1] * pref2[i + 1]) % m == r) {
            cout << i << ' ';
        }
    }

    return 0;
}
