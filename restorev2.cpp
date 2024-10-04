#include <bits/stdc++.h>
using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, nc;
    cin >> n;
    vector <int> d;
    for(int i = 1; i <= n; i++) {
        d.push_back(i);
    }
    for(int i1 = 0; i1 < n; i1++) {
        cin >> nc;
        int brh = d.size() - 1 - nc;
        cout << d[brh] << ' ';
        d.erase(d.begin() + brh);
    }
    return 0;
}
