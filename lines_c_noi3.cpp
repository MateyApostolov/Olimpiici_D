#include <bits/stdc++.h>
using namespace std;

const int maxn = 1001, d7 = pow(10, 9) + 7;
int mm[maxn][maxn], n, i, j;

int dp (int s, int p) {
    if(s == 2 && p == 2) return 1;
    if(mm[s][p] != 0) return mm[s][p];
    long long r = 0;
    for(int x = 2; x < p; x++) r += dp(s - x + 1, p - x + 1);
    for(int x = p + 1; x <= s; x++) r += dp(x - 1, x - p + 1);
    return mm[s][p] = r % d7;
}


int main () {
    cin >> n >> i >> j;
    cout << dp(n, j - i + 1);

    return 0;
}
