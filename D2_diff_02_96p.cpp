#include <bits/stdc++.h>
using namespace std;

bool is_prime (long long num) {
    double koren = sqrt(num);
    if(num <= 2) return true;
    for(int i = 2; i <= koren; i++) {
        if(num % i == 0) return false;
    }
    return true;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, h1, h2;
    cin >> n;
    h1 = n;
    while(h1 >= 2 && (!is_prime(h1) || !is_prime(h1 + n))) {
        h1--;
    }
    cout << n + h1 << ' ' << h1;
    return 0;
}

