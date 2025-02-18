#include <bits/stdc++.h>
using namespace std;

const int maxc = pow(10, 6) + 1;
int brdel[maxc];

void eratosten (int n) {
    for(int d = 1; d <= n; d++) {
        for(int h = d; h < maxc; h += d) {
            brdel[h]++;
        }
    }

    return;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q, m;
    cin >> n >> q;
    eratosten(n);
    for(int i = 0; i < q; i++) {
        cin >> m;
        cout << brdel[m - n] << '\n';
    }
    return 0;
}
