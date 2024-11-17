#include <bits/stdc++.h>
using namespace std;

long long nod(long long a, long long b) {
    if(a == 0) {
        return b;
    }
    if(b == 0) {
        return a;
    }
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, nc, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> nc;
        ans = nod(ans, nc);
    }
    cout << ans;
    return 0;
}
