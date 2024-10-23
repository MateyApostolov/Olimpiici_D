#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000;
int brm[maxn];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, t, l, r;
    string s;
    cin >> n >> s >> t;
    if(s[0] == '-') {
        brm[0]++;
    }
    for(int i = 1; i < n; i++) {
        brm[i] = brm[i - 1];
        if(s[i] == '-') {
            brm[i]++;
        }
    }
    for(int i1 = 0; i1 < t; i1++) {
        cin >> l >> r;
        int br = 0;
        for(int i2 = l - 1; i2 < r; i2++) {
            if(s[i2] == '+') {
                br += brm[r - 1] - brm[i2 - 1];
            }
        }
        cout << br << '\n';
    }

    return 0;
}
