#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000000;
long long pref[maxn];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, m, c, x, y;
    cin >> n >> m;
    cin >> c;
    pref[0] = c;
    for(int i = 1; i < n; i++) {
        cin >> c;
        pref[i] = pref[i - 1] + c;
    }
    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        if(x == 1) {
            cout << pref[y - 1] << '\n';
        } else {
            cout << pref[y - 1] - pref[x - 2] << '\n';
        }
    }

    return 0;
}
