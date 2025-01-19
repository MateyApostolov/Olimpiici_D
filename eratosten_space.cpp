#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000001;
bool del[maxn];
int prefd[maxn];

void eratosten () {
    for(long long d = 2; d <= maxn; d++) {
        if(del[d]) continue;
        prefd[d] = 1;
        for(long long k = d * d; k <= maxn; k += d) {
            del[k] = true;
        }
    }
    return;
}

int main () {
    int n, a, b;
    cin >> n;
    eratosten();
    for(int i = 2; i < maxn; i++) {
        prefd[i] += prefd[i - 1];
    }
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << prefd[b] - prefd[a - 1] << '\n';
    }

    return 0;
}

