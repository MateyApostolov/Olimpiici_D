#include <bits/stdc++.h>
using namespace std;

const int maxd = 1001;
int del[maxd];

void br_del(long long n) {
    int br = 0;
    for(int i = 1; i * i <= n; i++) {
        if(n % i != 0) continue;
        if(i * i == n) del[i]++;
        else {
            del[i]++;
            del[n / i]++;
        }
    }
    return;
}

int main () {
    long long n, br = 1;
    cin >> n;
    br_del(n);
    for(int i = 1; i <= maxd; i++) {
        br += del[i];
    }
    cout << br;
    return 0;
}
