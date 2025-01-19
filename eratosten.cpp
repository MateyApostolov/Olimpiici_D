#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000001;
bool del[maxn];

void eratosten (int n) {
    for(long long d = 2; d <= n; d++) {
        if(del[d]) continue;
        for(long long k = d * d; k <= n; k += d) {
            del[k] = true;
        }
    }
    return;
}

int main () {
    int n;
    cin >> n;
    eratosten(n);
    for(int i = 2; i < n; i++) {
        if(!del[i]) cout << i << ' ';
    }

    return 0;
}
