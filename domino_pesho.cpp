#include <bits/stdc++.h>
using namespace std;

const int d7 = pow(10, 9) + 7;
const int maxn = 2000;
int memoiz[maxn];

int dom (int num) {
    if(num == 1) return 1;
    if(num == 2) return 2;
    if(memoiz[num] != 0) return memoiz[num];
    memoiz[num] = (dom(num - 1) + dom(num - 2)) % d7;
    return memoiz[num];
}

int main () {
    int n;
    cin >> n;
    cout << dom(n);

    return 0;
}
