#include <bits/stdc++.h>
using namespace std;

int main () {
    string s1, s2;
    cin >> s1 >> s2;
    int dp[s1.size() + 1][s2.size() + 1];
    for(int r = 0; r <= s1.size(); r++) {
        for(int c = 0; c <= s2.size(); c++) {
            dp[r][c] = 0;
        }
    }
    for(int r = s1.size() - 1; r >= 0; r--) {
        for(int c = s2.size() - 1; c >= 0; c--) {
            if(s1[r] == s2[c]) dp[r][c] = dp[r + 1][c + 1] + 1;
            else dp[r][c] = max(dp[r + 1][c], dp[r][c + 1]);
        }
    }
    cout << dp[0][0];
    return 0;
}
