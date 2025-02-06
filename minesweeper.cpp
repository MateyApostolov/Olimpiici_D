#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, mul = 1, d7 = pow(10, 9) + 7;
    cin >> n;
    for(int i = 0; i < n; i++) {
        mul *= 2;
        mul %= d7;
    }
    cout << mul;
    return 0;
}
