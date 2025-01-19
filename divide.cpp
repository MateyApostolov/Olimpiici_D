#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000000;
int min_del[maxn], adel[maxn];

void eratosten (int n) {
    for(long long d = 2; d <= n; d++) {
        if(min_del[d] > 0) continue;
        for(long long k = d; k <= n; k += d) {
            if(min_del[k] == 0) min_del[k] = d;
        }
    }
    return;
}

int main () {
    int n, q, a, b;
    cin >> n >> q;
    eratosten(n);
    for(int i = 0; i < q; i++) {
        cin >> a >> b;
        a = a * b;
        int res = 1, ha = a;
        adel[maxn] = {};
        while(ha > 1) {
            adel[min_del[ha]]++;
            ha /= min_del[ha];
        }
        for(int x = 2; x <= a; x++) {
            int br = adel[x] / 2;
            while(br > 0) {
                res *= x;
                br--;
            }
        }
        cout << res << ' ';
    }

    return 0;
}
