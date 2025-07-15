#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    string s;
    int d2[n + 2][n + 2], dp[n + 2][n + 2];
    for(int r = 0; r <= n + 1; r++) {
        for(int c = 0; c <= n + 1; c++) {
            dp[r][c] = 0;
            if(c == 0 || c == n + 1 || r == 0 || r == n + 1) d2[r][c] = 0;
            else {
                cin >> s;
                if(s[0] == 'A') d2[r][c] = 1;
                else if(s[0] >= '2' && s[0] <= '9') d2[r][c] = s[0] - '0';
                else if(s[0] == 'T') d2[r][c] = 10;
                else if(s[0] == 'J') d2[r][c] = 11;
                else if(s[0] == 'Q') d2[r][c] = 12;
                else if(s[0] == 'K') d2[r][c] = 13;
            }
        }
    }
    for(int r = n; r >= 1; r--) {
        for(int c = 1; c <= n; c++) {
            dp[r][c] = d2[r][c] + max(dp[r][c - 1], dp[r + 1][c]);
        }
    }
    cout << dp[1][n];

    return 0;
}
