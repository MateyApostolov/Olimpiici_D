#include <bits/stdc++.h>
using namespace std;

long long nod(long long a, long long b) {
    long long host;
    if(a < b) {
        swap(a, b);
    }
    while(a % b != 0) {
        host = a % b;
        a = b;
        b = host;
    }
    return b;
}

int main () {
    long long a, b;
    cin >> a >> b;
    if(a == 0) {
        cout << b;
        return 0;
    }
    if(b == 0){
        cout << a;
        return 0;
    }
    cout << nod(a, b);
    return 0;
}
