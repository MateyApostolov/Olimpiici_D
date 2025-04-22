#include <bits/stdc++.h>
using namespace std;

int main () {
    long long n, sum = 0, ans;
    cin >> n;
    ans = n;
    long long nc[n];
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
    }
    sort(nc, nc + n);
    for(int i = 0; i < n; i++) {
        sum += nc[i];
        if(sum > n - i - 1) {
            break;
        }
        ans--;
    }
    cout << ans;
    return 0;
}
