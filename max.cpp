#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    string ns[n], bs = "", scbs = "";
    for(int i = 0; i < n; i++) {
        cin >> ns[i];
        if(ns[i].size() > bs.size()) {
            bs = ns[i];
            continue;
        }
        if(ns[i].size() == bs.size() && ns[i] > bs) {
            bs = ns[i];
        }
    }
    for(int i = 0; i < n; i++) {
        if(ns[i] == bs) continue;
        if(ns[i].size() > scbs.size()) {
            scbs = ns[i];
            continue;
        }
        if(ns[i].size() == scbs.size() && ns[i] > scbs) {
            scbs = ns[i];
        }
    }
    cout << scbs;
    return 0;
}
