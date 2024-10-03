#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000, koren = 100;
bool brc[maxn];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, nc;
    cin >> n;
    vector <int> d[koren];
    for(int i = 1; i <= n; i++) {
        d[i / koren].push_back(i);
    }
    for(int i1 = 0; i1 < n; i1++) {
        cin >> nc;
        int brh = n - i1 - nc;
        int h = 0;
        while(h < koren && brh > d[h].size()) {
            brh -= d[h].size();
            h++;
        }
        cout << d[h][brh - 1] << ' ';
        d[h].erase(d[h].begin() + brh - 1);
    }
    return 0;
}
