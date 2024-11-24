#include <bits/stdc++.h>
using namespace std;

const int maxiz = 1001;
int prefn[maxiz][maxiz], prefm[maxiz][maxiz], num[maxiz][maxiz];

int main () {
    int n, m;
    cin >> n >> m;
    for(int r = 1; r <= n; r++) {
        for(int k = 1; k <= m; k++) {
            cin >> prefn[r][k];
            num[r][k] = prefn[r][k] - (prefn[r - 1][k] + prefn[r][k - 1]) + prefn[r - 1][k - 1];
        }
    }
    for(int r = 1; r <= n; r++) {
        for(int k = 1; k <= m; k++) {
            cout << num[r][k] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
