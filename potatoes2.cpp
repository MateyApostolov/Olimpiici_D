#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, m, x, y;
    cin >> n >> m;
    x = n;
    y = m;
    long long d2[n + 1][m + 1], dp[n + 1][m + 1];
    for(int r = 0; r <= n; r++) {
        for(int c = 0; c <= m; c++) {
            if(r == 0 || c == 0) dp[r][c] = 0;
            else {
                cin >> d2[r][c];
                dp[r][c] = d2[r][c];
            }
        }
    }
    for(int r = 1; r <= n; r++) {
        for(int c = 1; c <= m; c++) {
            dp[r][c] += max(dp[r][c - 1], dp[r - 1][c]);
        }
    }
    vector <pair<int, int>> way;
    while(x >= 1 && y >= 1) {
        way.push_back({x, y});
        if(dp[x][y - 1] > dp[x - 1][y]) y--;
        else x--;
    }
    reverse(way.begin(), way.end());
    for(int i = 0; i < way.size(); i++) cout << way[i].first << ' ' << way[i].second << '\n';
    return 0;
}

