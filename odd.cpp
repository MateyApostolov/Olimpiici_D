#include <bits/stdc++.h>
using namespace std;

bool ncbr (int num) {
    int brc = 0;
    while(num > 0) {
        if((num % 10) % 2 == 1)  {
            brc++;
        }
        num /= 10;
    }
    if(brc % 2 == 1) return true;
    return false;
}

int main () {
    int n, m, br = 0;
    cin >> n >> m;
    while(n < m && n % 10000 != 0) {
        if(ncbr(n)) {
            br++;
        }
        n++;
    }
    while(n + 10000 < m) {
        br += 5000;
        n += 10000;
    }
    while(n <= m) {
        if(ncbr(n)) {
            br++;
        }
        n++;
    }
    cout << br;
    return 0;
}
