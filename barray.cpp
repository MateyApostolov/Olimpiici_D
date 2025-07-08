#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    long long nc[n + 1], pref[n + 1] = {};
    for(int i = 1; i <= n; i++) {
        cin >> nc[i];
        pref[i] = pref[i - 1] + nc[i];
    }
    for(int i = 1; i <= n; i++) {
        if(pref[i] == pref[n] - pref[i]) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
