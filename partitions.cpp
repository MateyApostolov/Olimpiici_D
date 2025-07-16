#include <bits/stdc++.h>
using namespace std;

const int maxn = 2001;
const int d7 = pow(10, 9) + 7;
int m[maxn][maxn];

int c (int sum, int x) {
    if(sum == 0) return 1;
    if(sum < 0) return 0;
    if(x <= 0) return 0;
    if(m[sum][x] != 0) return m[sum][x];
    return (c(sum, x - 1) + c(sum - x, x)) % d7;
}

int main () {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            m[i][j] = c(i, j);
        }
    }
    cout << c(n, n);
    return 0;
}

