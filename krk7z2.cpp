#include <bits/stdc++.h>
using namespace std;

const int maxc = pow(10, 5);
int prl[maxc], prr[maxc];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, t, tc;
    cin >> n;
    int nc[n];
    pair<int, int> lr[n];
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
        lr[i].first = prl[nc[i]];
        prl[nc[i]] = i + 1;
    }
    for(int i = n - 1; i >= 0; i--) {
        lr[i].second = prr[nc[i]];
        prr[nc[i]] = i + 1;
    }
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> tc;
        cout << lr[tc - 1].first << ' ' << lr[tc - 1].second << '\n';
    }
    return 0;
}
