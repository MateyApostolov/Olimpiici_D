#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, k;
    cin >> n >> k;
    int r1[n], r2[n];
    for(int i = 0; i < n; i++) cin >> r1[i];
    for(int i = 0; i < n; i++) cin >> r2[i];
    sort(r1, r1 + n);
    sort(r2, r2 + n);
    cout << r1[k / n] + r2[k % n];


    return 0;
}
