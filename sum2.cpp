#include <bits/stdc++.h>
using namespace std;

const int d7 = pow(10, 9) + 7;

int f2 (int num) {
    if(num == 0) return 1;
    if(num == 1) return 1;
    return (2 * f2(num - 1) + 1) % d7;
}

int main () {
    int n;
    cin >> n;
    cout << f2(n) - f2(n - 1);
    return 0;
}

