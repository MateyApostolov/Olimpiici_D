#include <bits/stdc++.h>
using namespace std;

const int maxn = pow(10, 6) + 1;
int pref[maxn];
bool used[maxn];

void eratosten () {
    long long mul;
    for(long long d = 2; d < maxn; d++) {
        if(used[d]) continue;
        mul = d * d;
        for(long long h = mul; h < maxn; h += d) {
            used[h] = true;
        }
    }
    return;
}

int main () {
    int k, a, b;
    cin >> k;
    eratosten();
    used[1] = true;
    for(int i = 1; i < maxn; i++) {
        pref[i] = pref[i - 1] + !used[i];
    }
    for(int i = 0; i < k; i++) {
        cin >> a >> b;
        cout << pref[b] - pref[a - 1] << '\n';
    }

    return 0;
}
