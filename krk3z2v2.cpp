#include <bits/stdc++.h>
using namespace std;

const int maxn = 100001;
bool isr[maxn];

int main () {
    int n, k, num, h = 0, izl = -1, izr = -1;
    cin >> n >> k;
    pair <int, int> nc[maxn];
    for(int i = 0; i < k; i++) {
        for(int f = 1; f <= k; f++) {
            cin >> num;
            h++;
            nc[h].first = num;
            nc[h].second = i;
        }
    }
    cout << "=============";
    sort(nc + 1, nc + h + 1);
    for(int l = 1; l <= h; l++) {
        for(int i = 1; i <= n; i++) {
            isr[i] = false;
        }
        for(int r = 1; r <= h; r++) {
            isr[nc[r].second] = true;
            int br = 0;
            for(int f = 1; f <= n; f++) {
                if(isr[f]) br++;
            }
            if(br == n) {
                if(nc[r].first - nc[l].first + 1 < izr - izl + 1) {
                    izl = nc[l].first;
                    izr = nc[r].first;
                } else if(nc[r].first - nc[l].first + 1 == izr - izl + 1)
                break;
            }
        }
    }
    cout << izl << ' ' << izr;
    return 0;
}
