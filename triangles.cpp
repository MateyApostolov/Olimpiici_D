#include <bits/stdc++.h>
using namespace std;

int main () {
    unsigned long long n, brb = 0, hn;
    cin >> n;
    hn = n;
    bool t = true;
    while(n > 0) {
        if(n < 4) {
            while(n < )
        }
        unsigned long long hi = floor(sqrt(n));
        n -= hi * hi;
        if(t) brb += hi * hi;
        t = !t;
    }
    cout << brb << ' ' << hn - brb;
    return 0;
}
