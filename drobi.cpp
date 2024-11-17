#include <bits/stdc++.h>
using namespace std;

int a, b, c, d, nok1, nod1, d1, d2;
char s, z;

int nod(int a, int b) {
    if(a < b) {
        swap(a, b);
    }
    if(b == 0) {
        return a;
    }
    int host;
    while(a % b != 0) {
        host = a % b;
        a = b;
        b = host;
    }
    return b;
}

int main () {
    cin >> a >> s >> b >> z >> c >> s >> d;
    nod1 = nod(d1, d2);
    if(z == '+') {
        d1 = a * d + b * c;
        d2 = b * d;
    }
    if(z == '-') {
        d1 = a * d - b * c;
        d2 = b * d;
    }
    if(z == '*') {
        d1 = a * c;
        d2 = b * d;
    }
    if(z == '/') {
        d1 = a * d;
        d2 = b * c;
    }
    nod1 = nod(d1, d2);
    d1 /= nod1;
    d2 /= nod1;
    if(d2 < 0) {
        d2 *= -1;
        d1 *= -1;
    }
    cout << d1 << '/' << d2;
    return 0;
}
