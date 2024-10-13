#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, lm = 0, ln = 0, br = 0;
    cin >> n >> m;
    int nc[n], mc[m];
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> mc[i];
    }
    sort(nc, nc + n);
    sort(mc, mc + m);
    vector <int> pn;
    while(ln < n && lm < m) {
        if(nc[ln] < mc[lm]){
            ++ ln;
        }
        else if(nc[ln] > mc[lm]){
            ++ lm;
        }
        else if(nc[ln] == mc[lm]) {
            pn.push_back(ln);
            ln++;
        }
    }
    cout << pn.size() << '\n';
    for(int i = 0; i < pn.size(); i++) {
        cout << nc[pn[i]] << ' ';
    }
    return 0;
}

