#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, d, maxbrk = 0, brr = 0, h;
    cin >> n >> d;
    int nc[n];
    unordered_map <int, int> brk;
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
        brk[nc[i] - d * i]++;
    }
    for(auto x : brk) {
        if(maxbrk < x.second) {
            maxbrk = x.second;
            h = x.first;
        }
    }
    for(int i = 0; i < n; i++) {
        if(nc[i] != h) {
            brr++;
        }
        h += d;
    }
    cout << brr;
    return 0;
}
