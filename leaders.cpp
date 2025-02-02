#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, maxc = 0;
    cin >> n;
    int nc[n];
    vector <int> lead;
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
    }
    reverse(nc, nc + n);
    for(int i = 0; i < n; i++) {
        if(maxc <= nc[i]) {
            maxc = nc[i];
            lead.push_back(maxc);
        }
    }
    reverse(lead.begin(), lead.end());
    for(int i = 0; i < lead.size(); i++) {
        cout << lead[i] << ' ';
    }
    return 0;
}
