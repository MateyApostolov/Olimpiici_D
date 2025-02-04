#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, a, b, brt = 0;
    cin >> n;
    unordered_map <int, int> mp;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        if(a < 0 || b < 0)  continue;
        if(a + b + 1 != n) continue;
        mp[a]++;
    }
    cout << mp.size();
    return 0;
}
