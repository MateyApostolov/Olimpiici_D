#include <bits/stdc++.h>
using namespace std;

int const maxn = pow(10, 6) + 1;
bool er[maxn];
int brpr[maxn];
vector <int> primen;

void eratosten () {
    for(int d = 2; d * d < maxn; d++) {
        if(!er[d]) {
            for(int h = d * d; h < maxn; h += d) {
                er[h] = true;
            }
        }
    }
    return;
}

void set_p () {
    for(int i = 2; i < maxn; i++) {
        if(!er[i]) {
            primen.push_back(i);
        }
    }
    return;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, r = -1, bigd = 1;
    eratosten ();
    set_p ();
    cin >> n >> k;
    int nc[n];
    vector <vector <int>> rc(n);
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
        int h = nc[i], in = 0;
        while(h > 1) {
            if(!er[h]) {
                rc[i].push_back(h);
                break;
            }
            if(h % primen[in] == 0) {
                rc[i].push_back(primen[in]);
            }
            while(h % primen[in] == 0) {
                h = h / primen[in];
            }
            in++;
        }
    }
    for(int i1 = 0; i1 < k - 1; i1++) {
        for(int i2 = 0; i2 < rc[i1].size(); i2++) {
            brpr[rc[i1][i2]]++;
        }
    }
    for(int i1 = k - 1; i1 < n; i1++) {
        int d = 1;
        for(int i2 = 0; i2 < rc[i1].size(); i2++) {
            brpr[rc[i1][i2]]++;
            if(brpr[rc[i1][i2]] == k) {
                d = rc[i1][i2];
            }
        }
        for(int i2 = 0; i2 < rc[i1 - k + 1].size(); i2++) {
            brpr[rc[i1 - k + 1][i2]]--;
        }
        bigd = max(bigd, d);
    }
    cout << bigd;
    return 0;
}
