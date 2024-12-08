#include <bits/stdc++.h>
using namespace std;

long long my_pow(long long num, long long st) {
    int n = 1;
    for(int i = 0; i < st; i++) {
        n *= num;
    }
    return n;
}

int main () {
    long long p, n, c = 1, sk = 0;
    cin >> p >> n;
    while(n > (p - 1) * my_pow(p, c - 1) * c) {
        n -= (p - 1) * my_pow(p, c - 1) * c;
        c++;
        sk += (p - 1) * my_pow(p, c - 1) * c;
    }
    if(n % c == 0) {
        sk += n / c - 1;
    } else {
        sk += n / c;
    }
    string s = ten_to_pbr(sk + 1, p);
    if(x % c == 0) {
        cout << s[s.size() - 1];
    } else {

    }
    return 0;
}
