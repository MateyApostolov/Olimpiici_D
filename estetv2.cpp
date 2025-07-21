#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, ans = 0;
    cin >> n;
    int nc[n], dp1[n], dp2[n];
    vector <int> maxi1, maxi2;
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
    }
    for(int i = 0; i < n; i++) {
        auto it = lower_bound(maxi1.begin(), maxi1.end(), nc[i]);
        if(it != maxi1.end()) *it = nc[i];
        else maxi1.push_back(nc[i]);
        dp1[i] = maxi1.size();
    }
    for(int i = n - 1; i >= 0; i--) {
        auto it = lower_bound(maxi2.begin(), maxi2.end(), nc[i]);
        if(it != maxi2.end()) *it = nc[i];
        else maxi2.push_back(nc[i]);
        dp2[i] = maxi2.size();
    }
    for(int i = 0; i < n; i++) {
        ans = max(ans, dp1[i] + dp2[i] - 1);
    }
    cout << ans;
    return 0;
}
