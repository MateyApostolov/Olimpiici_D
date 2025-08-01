#include <bits/stdc++.h>
using namespace std;

int main () {
    int x = 11;
    x = x >> 1;
    cout << x << '\n';
    x = x << 1;
    cout << x << '\n';
    x = 1 << 10;
    cout << x << '\n';
    x = 11 & 13;
    cout << x << '\n';
    x = 11 | 9;
    cout << x << '\n';
    x = x | (1 << 31);
    cout << x << '\n';
    cout << ((x << 1)>> 1);
    return 0;
}
