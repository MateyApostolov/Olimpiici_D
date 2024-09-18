#include <bits/stdc++.h>
using namespace std;

bool is_fivediv(long long num) {
    int br = 1;
    for(int i = 1; i * i < num; i++) {
        if(num % i == 0) {
            br += 2;
        }
    }
    if(br == 5) return true;
    return false;
}

int main () {
    long long n, sum = 0;
    cin >> n;
    for(long long i = 1; i * i * i * i <= n; i++) {
        long long kw = i * i * i * i;
        if(is_fivediv(kw)) {
            sum += kw;
        }
    }
    cout << sum;
    return 0;
}
