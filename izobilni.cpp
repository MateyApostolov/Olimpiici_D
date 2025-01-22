#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000001;
int sumdel[maxn], prefd[maxn];

void eratosten (int n) {
    for(long long d = 1; d < n; d++) {
        for(long long k = 2 * d; k <= n; k += d) {
            sumdel[k] += d;
        }
    }
    return;
}

int main () {
    int q, a, b;
    cin >> q;
    eratosten(maxn);
    for(int i = 1; i < maxn; i++) {
        if(sumdel[i] >= i) prefd[i] = prefd[i - 1] + 1;
        else prefd[i] = prefd[i - 1];
    }
    for(int i = 0;  i < q; i++) {
        cin >> a >> b;
        cout << prefd[b] - prefd[a - 1] << '\n';
    }

    return  0;
}
