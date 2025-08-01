#include <bits/stdc++.h>
using namespace std;


const int maxn = 1001;
double n, m, mm[maxn][maxn];
pair <int, double> nc[maxn];

double dp(int sum, int i) {
    if(i > n) return 0;
    if(mm[sum][i] != 0) return mm[sum][i];
    double v1 = -1, v2;
    if(sum - nc[i].first >= 0) v1 = nc[i].second + dp(sum - nc[i].first, i + 1);
    v2 = dp(sum, i + 1);
    return mm[sum][i] = max(v1, v2);
}

int main () {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> nc[i].first >> nc[i].second;
    }
    cout << fixed  << setprecision(2) << dp(m, 1);
    return 0;
}
