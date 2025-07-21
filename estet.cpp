#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, ans = 0;
    cin >> n;
    int nc[n], dp1[n], dp2[n];
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
        dp1[i] = 1;
        dp2[i] = 1;
    }
    for(int i = 0; i < n; i++) {
        for(int x = 0; x < i; x++) {
            if(nc[x] >= nc[i]) continue;
            if(dp1[i] < dp1[x] + 1) dp1[i] = dp1[x] + 1;
        }
    }
    for(int i = n - 1; i >= 0; i--) {
        for(int x = i + 1; x < n; x++) {
            if(nc[x] >= nc[i]) continue;
            if(dp2[i] < dp2[x] + 1) dp2[i] = dp2[x] + 1;
        }
    }
    for(int i = 0; i < n; i++) cout << dp1[i] << ' ';
    cout << '\n';
    for(int i = 0; i < n; i++) cout << dp2[i] << ' ';
    cout << '\n';
    for(int i = 0; i < n; i++) {
        ans = max(ans, dp1[i] + dp2[i] - 1);
    }
    cout << ans;
    return 0;
}
