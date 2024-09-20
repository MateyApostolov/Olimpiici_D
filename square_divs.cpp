#include <bits/stdc++.h>
using namespace std;

long long br_del(unsigned long long n) {
    long long br = 0;
    for(long long i = 1; i * i <= n; i++) {
        if(n % i != 0) continue;
        if(i * i == n) br++;
        else br += 2;
    }
    return br;
}

int main () {
    long long n;
    cin >> n;
    cout << br_del(n * n);

    return 0;
}
