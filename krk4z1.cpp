#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, h = 0, i = 0;
    cin >> n >> m;
    int nc[n], mc[m];
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> mc[i];
    }
    while (i < n && h < m) {
        while(h < m && mc[h] <= nc[i]) {
            cout << mc[h] << ' ';
            h++;
        }
        while(i < n && mc[h] > nc[i]) {
            cout << nc[i] << ' ';
            i++;
        }
    }
    while(i < n) {
        cout << nc[i] << ' ';
        i++;
    }
    while(h < m) {
        cout << mc[h] << ' ';
        h++;
    }
    return 0;
}
