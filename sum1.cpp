#include <bits/stdc++.h>
using namespace std;

const int d7 = pow(10, 9) + 7;
const int maxn = pow(10, 6);
int memoiz[maxn];

int sum (int num) {
    if(num == 0) return 1;
    if(memoiz[num] != 0) return memoiz[num];
    int h = 0;
    for(int i = 1; i <= num; i++) {
        h += sum(num - i);
        h %= d7;
    }
    memoiz[num] = h;
    return h;
}

int main () {
    int n;
    cin >> n;
    cout << sum(n);
    return 0;
}

