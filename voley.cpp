#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    int nc[n], mc[m];
    vector <int> alsum;
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> mc[i];
    }
    for(int i1 = 0; i1 < n - 1; i1++) {
        for(int i2 = i1 + 1; i2 < n; i2++) {
            alsum.push_back(nc[i1] + nc[i2]);
        }
    }
    sort(alsum.begin(), alsum.end());
    sort(mc, mc + m);
    for(int i1 = 0; i1 < alsum.size(); i1++) {
        int l = 0, r = m - 1;
        while(l < r) {
            if(mc[l] + mc[r] == alsum[i1]) {
                cout << alsum[i1];
                return 0;
            }
            if(mc[l] + mc[r] < alsum[i1]) {
                l++;
            } else {
                r--;
            }
        }
    }
    cout << "no volleyball today";
    return 0;
}
