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
    return (c(sum, x - 2) + c(sum - x, x)) % d7;
}

int main () {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(j % 2 == 0) m[i][j] = c(i, j - 1);
            else m[i][j] = c(i, j);
        }
    }
    if(n % 2 == 0) cout << c(n, n - 1);
    else cout << c(n, n);
    return 0;
}

