#define _GLIBCXX_FILESYSTEM
#include <bits/stdc++.h>
using namespace std;

const int maxm = 100000;
bool isc[maxm];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, nc;
    cin >> n >> m;
    m += 13000;
    map <int, bool> mp;
    for(int i = 0; i < n; i++) {
        cin >> nc;
        nc += 13000;
        if(nc >= 0) isc[nc] = true;
    }
    for(int i = m + 1; i <= maxm; i++) {
        if(!isc[i]) {
            cout << i - 13000;
            break;
        }
    }
    return 0;
}


