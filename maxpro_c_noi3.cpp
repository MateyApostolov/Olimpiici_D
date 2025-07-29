#include <bits/stdc++.h>
using namespace std;

const int maxn = 201;
long long n, mm[maxn][maxn];

long long dp(long long sum, long long prc) {
    if(sum < 0) return 0;
    if(sum == 0) return prc;
    if(mm[sum][prc] != 0) return mm[sum][prc];
    long long mul = 1;
    for(long long i = prc - 1; i >= 1; i--) {
        mul = max(mul, dp(sum - i, i));
    }
    if(prc == n) return mm[sum][prc] = mul;
    return mm[sum][prc] = prc * mul;
}

int main () {
    cin >> n;
    cout << dp(n, n);

    return 0;
}
