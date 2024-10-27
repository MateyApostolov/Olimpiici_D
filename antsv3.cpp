#include <bits/stdc++.h>
using namespace std;

const int maxn = pow(10, 5) + 1;
int prefm[maxn], prefp[maxn], prefs[maxn];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, t, l, r;
    string s;
    cin >> n >> s >> t;
    for(int i = n - 1; i >= 0; i--) {
        prefm[i] = prefm[i + 1];
        prefp[i] = prefp[i + 1];
        prefs[i] = prefs[i + 1];
        if(s[i] == '-') {
            prefm[i]++;
        } else {
            prefp[i]++;
            prefs[i] += prefm[i];
        }
    }
    for(int i = 0; i < t; i++) {
        cin >> l >> r;
        l--;
        r--;
        int sol;
        if(s[r] == '+') {
            sol = prefs[l] - prefs[r + 1] - (prefp[l] - prefp[r] + 1) * prefm[r + 1];
        } else {
            sol = prefs[l] - prefs[r + 1] - (prefp[l] - prefp[r]) * prefm[r + 1];
        }
        cout << sol << '\n';
    }


    return 0;
}
