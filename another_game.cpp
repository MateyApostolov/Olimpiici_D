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
        for(int x = 0; x < n; x++) {
            if(s[x] > qc) {
                if(i == q - 1) cout << sum2;
                else cout << sum2 << ' ';
                break;
            }
            sum2 += pow(2, x);
        }
        if(s[n - 1] <= qc) {
            if(i == q - 1) cout << sum2;
            else cout << sum2 << ' ';
        }
    }
    return 0;
}
