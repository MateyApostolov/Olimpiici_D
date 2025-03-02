#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, q, qc;
    cin >> n >> q;
    long long s[n];
    cin >> s[0];
    for(int i = 1; i < n; i++) {
        cin >> s[i];
        s[i] *= s[i - 1];
    }
    for(int i = 0; i < q; i++) {
        cin >> qc;
        long long sum2 = 1;
        for(int x = n - 1; x >= 0; x--) {
            if(s[x] > qc) continue;
            qc -= s[x];
            sum2 += pow(2, x);
        }
        cout << sum2 << ' ';
    }
    return 0;
}
