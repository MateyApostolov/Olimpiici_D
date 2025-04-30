#include <bits/stdc++.h>
using namespace std;

int main () {
    long long n, ans = 0, d7 = pow(10, 9) + 7, j, hnum = 1;
    cin >> n;
    long long nc[n + 1];
    vector <long long> st2;
    for(int i = 1; i <= n; i++) {
        cin >> nc[i];
    }
    for(int i = 0; i <= n; i++) {
        st2.push_back(hnum);
        hnum *= 2;
        hnum %= d7;
    }
    for(int i = 1; i <= n; i++) {
        long long hnum = 0;
        for(int j = i + 1; j <= n; j++) {
            if(nc[j] == nc[i]) continue;
            hnum += (st2[i - 1] * st2[n - j]) % d7;
            hnum %= d7;
        }
        ans = (ans + (hnum + 1) % d7) % d7;
    }
    ans = (ans + st2[n - 1]) % d7;
    cout << ans;
    return 0;
}
