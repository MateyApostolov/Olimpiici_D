#include <bits/stdc++.h>
using namespace std;

long long nod(long long a, long long b) {
    if(a < b) {
        swap(a, b);
    }
    if(b == 0) {
        return a;
    }
    long long host;
    while(a % b != 0) {
        host = a % b;
        a = b;
        b = host;
    }
    return b;
}

int main () {
    long long n, m, ans;
    cin >> n >> m;
    ans = nod(n, m);
    cout << n / ans;

    return 0;
}
