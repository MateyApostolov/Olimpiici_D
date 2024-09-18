#include <bits/stdc++.h>
using namespace std;

bool is_prime(long long num) {
    for(long long i = 2; i * i <= num; i++) {
        if(num % i == 0) return false;
    }
    return true;
}

int main () {
    long long n, sum = 0;
    cin >> n;
    for(long long i = 2; i * i * i * i <= n; i++) {
        if(is_prime(i)) sum += i * i * i * i;
        ///cout << sum << ' ' << i << '\n';
    }
    cout << sum;
    return 0;
}
