#include <bits/stdc++.h>
using namespace std;

const int maxn = 271;
long long mm[maxn][maxn];

long long dp(int sum, int prc) {
    if(sum < 0) return 0;
    if(sum == 0) return 1;
    if(mm[sum][prc] != 0) return mm[sum][prc];
    long long ans = 0;
    for(int i = prc;  i >= 1; i--) {
        ans += dp(sum - i, i);
    }
    mm[sum][prc] = ans;
    return ans;
}

int main () {
    int n, m;
    cin >> n >> m;
    cout << dp(n, m);

    return 0;
}
