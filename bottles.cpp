#include <bits/stdc++.h>
using namespace std;

const int maxn = pow(10, 5) + 1;
int nc[maxn], memoiz[maxn];

int maxb (int num) {
    if(num <= 0) return 0;
    if(memoiz[num] != 0) return memoiz[num];
    memoiz[num] = max(maxb(num - 1), maxb(num - 2) + nc[num]);
    return max(maxb(num - 1), maxb(num - 2) + nc[num]) ;
}

int main () {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> nc[i];
    cout << maxb(n);

    return 0;
}
