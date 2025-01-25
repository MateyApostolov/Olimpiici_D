#include <bits/stdc++.h>
using namespace std;

const int maxn = pow(10, 5);
int f[maxn];

int main () {
    int n, k, num;
    cin >> n >> k;
    map <int, bool> mpc;
    vector <int> nc;
    for(int i = 0; i < k; i++) {
        cin >> num;
        mpc[num] = true;
    }
    for(auto x : mpc) nc.push_back(x.first);
    for(int i = 1; i <= n; i++) {
        int maxc = 0;
        for(int x = 0; x < nc.size(); x++) {
            if(i - nc[x] < 0) continue;
            maxc = max(maxc, f[i - nc[x]]);
        }
        if(maxc != 0) f[i] = maxc + 1;
        else {
            for(int x = 0; x < nc.size(); x++) {
                if(nc[x] == i) {
                    f[i] = 1;
                    break;
                }
            }
        }
    }
    if(f[n] == 0) f[n] = -1;
    cout << f[n];
    return 0;
}
