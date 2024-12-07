#include <bits/stdc++.h>
using namespace std;

const int maxiz = 1001;
int prefn[maxiz][maxiz], num[maxiz][maxiz];

bool is_prime(int num) {
    double koren = sqrt(num);
    if(num <= 1) return false;
    int i;
    for(i = 2; i < koren; i++) {
        if(num % i == 0) return false;
    }
    if(i * i == num) return false;
    return true;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, brpr = 0;
//    cin >> n; cout << is_prime(n); return 0;
    cin >> n >> m;
    for(int r = 1; r <= n; r++) {
        for(int k = 1; k <= m; k++) {
            cin >> num[r][k];
            prefn[r][k] = prefn[r][k - 1] + prefn[r - 1][k] - prefn[r - 1][k - 1] + num[r][k];
        }
    }
    for(int r1 = 1; r1 <= n; r1++) {
        for(int k1 = 1; k1 <= m; k1++) {
            for(int r2 = r1; r2 <= n; r2++) {
                for(int k2 = k1; k2 <= m; k2++) {
                    if(is_prime(prefn[r2][k2] - prefn[r1 - 1][k2] - prefn[r2][k1 - 1] + prefn[r1 - 1][k1 - 1])) {
                        brpr++;
                    }
                }
            }
        }
    }
    cout << brpr;
    return 0;
}

