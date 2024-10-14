#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, num;
    cin >> n;
    pair <int, int> nc[n];
    int iz[n];
    for(int i = 0; i < n; i++) {
        cin >> num;
        nc[i].first = num;
        nc[i].second = i;
        iz[i] = -1;
    }
    sort(nc, nc + n);
    for(int i = 1; i < n; i++) {
        if(nc[i].first == nc[i - 1].first) {
            iz[nc[i].second] = nc[i - 1].second;
        }
    }
    for(int i = 0; i < n; i++) {
        cout << iz[i] << ' ';
    }

    return 0;
}

