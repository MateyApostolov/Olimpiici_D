#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, nc;
    cin >> n;
    vector <int> ac, sortc;
    for(int i1 = 0; i1 < n; i1++) {
        cin >> nc;
        int brh = n - nc, h = brh;
        sort(sortc.begin(), sortc.end());
        for(int i2 = sortc.size() - 1; i2 >= 0; i2--) {
            if(sortc[i2] >= brh) {
                brh--;
            } else {
                break;
            }
        }
        ac.push_back(brh);
        sortc.push_back(brh);
    }
    for(int i = 0; i < ac.size(); i++) {
        cout << ac[i] << ' ';
    }
    return 0;
}
