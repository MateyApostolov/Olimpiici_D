#include <bits/stdc++.h>
using namespace std;


int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

void extended_evklid(int a, int b, int &x1, int &y1) {
    int q, r, x2, y2, t;
    x1 = 1;
    y1 = 0;
    x2 = 0;
    y2 = 1;
    while(b != 0) {
        q = a / b;
        r = a % b;
        a = b;
        b = r;

        t = x2;
        x2 = x1 - q * x2;
        x1 = t;

        t = y2;
        y2 = y1 - q * y2;
        y1 = t;
    }
}


int main  () {
    int a, b, c = 1, x1, y1, k, d;
    cin >> a >> b;
    d = gcd(a, b);
    if(c % d != 0) {
        cout << "Impossible";
        return 0;
    }
    a /= d;
    b /= d;
    c /= d;
    extended_evklid(a, b, x1, y1);
    x1 *= c;
    y1 *= c;
    cout << y1 / a - ( - x1 / b) + 1 << '\n';


    return 0;
}

