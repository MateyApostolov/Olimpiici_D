#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    long long nc, dp[n + 1] = {}, sum = 0;
    unordered_map <long long, int> mp;
    mp[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> nc;
        sum += nc;
        auto t = mp.find(sum);
        if(t != mp.end()) dp[i] = max(dp[i - 1], dp[mp[sum]] + 1);
        else dp[i] = dp[i - 1];
        mp[sum] = i;
    }
    cout << dp[n];
    return 0;
}
