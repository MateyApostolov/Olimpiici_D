#include <bits/stdc++.h>
using namespace std;

const int maxc = 1000001;
int p[maxc];

int main () {
    int n;
    cin >> n;
    int nc[n];
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
        p[nc[i]] = -1;
    }
    for(int i = 0; i < n; i++) {
        cout << p[nc[i]] << ' ';
        p[nc[i]] = i;
    }
    return 0;
}
