#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, nc;
    cin >> n;
    map <int, bool> mp;
    for(int i = 0; i < n; i++) {
        cin >> nc;
        mp[nc] = true;
    }
    cout << mp.size();
}
