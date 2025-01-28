#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    int nc[n];
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
        int h = i;
        while(h >= 0 && nc[h] >= nc[i]) {
            h--;
        }
        cout << h + 1 << ' ';
    }

    return 0;
}
