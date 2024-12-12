#include <bits/stdc++.h>
using namespace std;

int main () {
    unsigned long long g, l, mul, brd = 0;
    cin >> g >> l;
    mul = g * l;
    for(unsigned long long i = 1; i * i <= mul; i++) {
        if(mul % i == 0) {
            unsigned long long a = i, b = mul / i, nod = __gcd(a, b);
            if(g == nod) {
                brd++;
            }
        }
    }
    cout << brd;
    return 0;
}
