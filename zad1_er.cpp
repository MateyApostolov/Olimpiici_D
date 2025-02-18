#include <bits/stdc++.h>
using namespace std;

const int maxn = 5 * pow(10, 6);
int brdel[maxn];

void eratosten (int n) {
    for(int d = 1; d <= n; d++) {
        for(int h = d; h <= n; h += d) {
            brdel[h]++;
        }
    }
    return;
}

int main () {
    int n, maxd = 0, num = 0;
    cin >> n;
    eratosten(n);
    for(int i = 1; i <= n; i++) {
        if(maxd < brdel[i]) {
            maxd = brdel[i];
            num = i;
        }
    }
    cout << num << '\n' << brdel[num];
    return 0;
}
