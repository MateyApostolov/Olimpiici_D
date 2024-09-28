#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, k, h = 2, x = 0;
    cin >> n >> k;
    vector <int> nc;
    while(h < n) {
        for(int i = 1; i <= h; i++) {
            nc.push_back(i);
        }
        nc.erase(nc.begin() + (k % h));
        if(x < n - k) {
            x = x + k;
        } else {
            x = x - (n - k + x);
        }
        h++;
        nc.clear();
    }
    cout << nc[x + 1];
    return 0;
}
