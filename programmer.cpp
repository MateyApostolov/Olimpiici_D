#include <bits/stdc++.h>
using namespace std;

int main () {
    long long n, brb = 0, br = 0;
    cin >> n;
    ///for(int i = 1; i <= n; i++) brb += n / i;
    for(int i = 1; i <= n / 100; i++) br += n / i;
    for(int i = 2; i <= 100; i++) br += (n / (i - 1) - n / i) * (i - 1);
    ///cout << brb - br;
    cout << br;
    return 0;
}
