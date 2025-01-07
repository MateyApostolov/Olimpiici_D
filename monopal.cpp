#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, nc, minraz = 250000;
    cin >> n;
    if(n % 2 != 0) {
        cout << 0;
        return 0;
    }
    pair <pair<int, int>, char> nr[n];
    for(int i = 1; i <= n; i++) {
        cin >> nc;
        if(i <= n / 2) nr[i - 1] = {{nc, i}, 'l'};
        else nr[i - 1] = {{nc, n - i + 1}, 'r'};
    }
    sort(nr, nr + n);
    for(int i = 0; i < n - 1; i++) {
        if(nr[i].first.first != nr[i + 1].first.first) continue;
        if(nr[i].second != nr[i + 1].second) minraz = min(minraz, nr[i + 1].first.second - nr[i].first.second);
        else minraz = min(minraz, n - nr[i + 1].first.second + 1 - nr[i].first.second);
    }
    cout << minraz;
    return 0;
}
