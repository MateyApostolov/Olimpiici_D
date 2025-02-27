#include <bits/stdc++.h>
using namespace std;

const int maxn = 5001;
bool sh[maxn][maxn];

int main () {
    int n, m, ans = 1;
    cin >> n >> m;
    for(int i = 1; i < n; i++) {
        for(int x = 0; x < m; x++) {
            if(sh[i][x]) continue;
            ans++;
            int hi = i, hx = x;
            while(hi < n && hx < m) {
                sh[hi][hx] = true;
                hi += i;
                hx += x;
            }
        }
    }
    cout << ans;
    return 0;
}
