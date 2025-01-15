#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, Dx = 2, old = 4, rr;
///    cin >> n;
    for(n = 1; n <= 20; n++) {
        int br3 = 0, i = 0;
        while(i < pow(2, n)) {
            int h = i/2, h2 = 1, brs = 0;
            while(h2 < n) {
                if(h % 2 == 0) brs++;
                h /= 2;
                h2++;
            }
            if(brs % 3 == 0) br3++;
            i++;
        }
        if(n % 3 == 1){
            rr = old * 2;
            Dx = -Dx;
        } else rr = old * 2 + Dx;
        cout << n << ' ' << br3 << " - " << rr<< '\n';
        old = br3;
    }
    return 0;
}
