#include <bits/stdc++.h>
using namespace std;

int fac (int ind) {
    if(ind == 0) return 1;
    else return fac(ind - 1) * ind;
}

int fib(int ind) {
    if(ind <= 2) return 1;
    else return fib(ind - 1) + fib(ind - 2);
}

int main () {
    int n;
    cin >> n;
    cout << fac(n) << '\n';
    cout << fib(n) << '\n';
    return 0;
}
