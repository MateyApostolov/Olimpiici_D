#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000;
bool brc[maxn];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, nc;
    cin >> n;
    for(int i1 = 0; i1 < n; i1++) {
        cin >> nc;
        int brh = n - nc;
        for(int i2 = n; i2 >= brh; i2--) {
            if(brc[i2]) {
                brh--;
            }
        }
        brc[brh] = true;
        cout << brh << ' ';
    }
    return 0;
}
