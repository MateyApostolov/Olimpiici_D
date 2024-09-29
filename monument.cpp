#include <bits/stdc++.h>
using namespace std;

const int maxn = 300000;

int main () {
    long long n, kr, brd = 0;
    cin >> n >> kr;
    long long nc[maxn];
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
    }
    long long l = -1;
    for(long long r = 0; r < n; r++) {
        while(l < r && nc[r] - nc[l + 1] > kr) {
            l++;
        }
        brd += l + 1;
    }
    cout << brd;
    return 0;
}
