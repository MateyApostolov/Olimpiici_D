#include <bits/stdc++.h>
using namespace std;

int main () {
    long long a, b, c, t, d;
    cin >> a >> b >> c >> t >> d;
    long long nok = a * b / __gcd(a, b), mind = d * t - 1, minpr = (d - 1) * t - 1;
    nok = nok * c / __gcd(nok, c);
    long long brk = mind / nok - minpr / nok;
    if(d == 1) brk++;
    cout << brk;

    return 0;
}
