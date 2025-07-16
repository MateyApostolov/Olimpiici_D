#include <bits/stdc++.h>
using namespace std;

const int maxn = 20;
int w[maxn], v[maxn];

int bc(int wt, int k) {
    if(wt <= 0) return 0;
    if(k <= 0) return 0;
    int ans = bc(wt, k - 1);
    if(wt >= w[k]) ans = max(ans, bc(wt - w[k], k - 1) + v[k]);
    return ans;
}

int main () {
    int n, wt;
    cin >> n >> wt;
    for(int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    cout << bc(wt, n);
    return 0;
}
