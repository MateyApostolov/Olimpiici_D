#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000001;
int nc[maxn], pref[maxn];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, s, br = 0;
    cin >> n >> s;
    cin >> nc[0];
    pref[0] = nc[0];
    for(int i = 1; i < n; i++) {
        cin >> nc[i];
        pref[i] = pref[i - 1] + nc[i];
    }
    for(long long l = 0; l < n; l++) {
        ///cout << br << '\n';
        long long r = max(l - 1, (long long)0);
        while(r + 1 < n) {
            if((l > 0 && pref[r + 1] - pref[l - 1] > s) || (l == 0 && pref[r + 1] > s)) break;
            r++;
        }
        if((l > 0 && pref[r] - pref[l - 1] == s) || (l == 0 && pref[r] == s)) {
            br++;
        }
        l = r;
    }
    cout << br;
    return 0;
}

