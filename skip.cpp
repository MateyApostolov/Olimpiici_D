#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, h = 2, pr, hn;
    cin >> n;
    pr = n;
    hn = n;
    int nc[n];
    for(int i = 1; i <= n; i++) {
        nc[i] = i;
    }
    while(hn != 1) {
        for(int i = 1; i <= n; i++) {
            if(i % h == 0){
                nc[i] = 0;
            }
            hn = max(hn, nc[i]);
        }
        h++;
        pr = hn;
    }
    cout << pr;
    return 0;
}
