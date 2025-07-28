#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, ans = 0;
    cin >> n;
    int nc[n], dp1[n];
    vector <int> maxi1;
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
    }
    for(int i = 0; i < n; i++) {
        auto it = lower_bound(maxi1.begin(), maxi1.end(), nc[i]);
        if(it != maxi1.end()) *it = nc[i];
        else maxi1.push_back(nc[i]);
        dp1[i] = maxi1.size();
    }
    for(int i = 0; i < n; i++) {
        ans = max(ans, dp1[i]);
    }
    cout << ans;
    return 0;
}
