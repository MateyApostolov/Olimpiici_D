#include <bits/stdc++.h>
using namespace std;

int main () {
    long long s, n;
    cin >> s;
    n = sqrt(s);
    while(s - ((n + 1) * n) / 2 > n) {
        n++;
    }
    if(s - ((n + 1) * n) / 2 <= 0) {
        cout << '0';
    } else {
        cout << n << ' ' << s - ((n + 1) * n) / 2;
    }
    return 0;
}
