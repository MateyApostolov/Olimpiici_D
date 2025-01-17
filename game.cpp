#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, s1 = 0, s2 = 0, num;
    cin >> n;
    bool red = false;
    vector <int> nc[n];
    for(int r = 0; r < n; r++) {
        for(int c = 0; c < n; c++) {
            cin >> num;
            nc[r].push_back(num);
        }
        sort(nc[r].begin(), nc[r].end());
    }
    while(true) {
        int izr = 0, minc = INT_MAX;
        bool t = false;
        for(int r = 0; r < n; r++) {
            if(!nc[r].empty()) t = true;
            else continue;
            if(minc > nc[r].back()) {
                minc = nc[r].back();
                izr = r;
            }
        }
        if(!t) break;
        if(red) s1 += minc;
        else s2 += minc;
        red = !red;
        nc[izr].pop_back();
    }
    cout << s1 << ' ' << s2;
    return 0;
}
