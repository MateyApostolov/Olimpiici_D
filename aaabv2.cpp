#include <bits/stdc++.h>
using namespace std;

int main () {
    long long n, Dx = -2, old = 2, rr;
    cin >> n;
    for(int x = 4; x <= n; x++) {
        if(x % 3 == 1){
            rr = old * 2;
            Dx = -Dx;
        } else rr = old * 2 + Dx;
        old = rr;
    }
    cout << rr;
    return 0;
}
