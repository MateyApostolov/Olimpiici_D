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
    int a, b, c, d, u, v;
    cin >> a >> b >> c;
    d = gcd(a, c);
    if(b % d != 0) {
        cout << "No";
        return 0;
    }
    extended_evklid(c, a, u, v);
    if(d == 1) {
        int x = (b * v) % c;
        if(x < 0) x += c;
        cout << x << '\n';
    } else {
        a /= d;
        b /= d;
        c /= d;
        int x = (b * v) % c;
        for(int i = 0; i < d; i++) {
            if(x < 0) x += c;
            cout << x + i * c << '\n';
        }
    }



    return 0;
}
