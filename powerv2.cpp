#include <bits/stdc++.h>
using namespace std;

const int maxn = pow(10, 5) * 2 + 1, d7 = pow(10, 9) + 7, d9 = pow(10, 9) + 9;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, q, l, r, iz7 = 0, iz9 = 0;
    cin >> n >> q;
    int nc[n + 1], k[n + 1] = {}, h = 0, prs = 0;
    pair<int, int> qc[q];
    vector <pair<int, int>> rh;
    for(int i = 1; i <= n; i++) {
        cin >> nc[i];
    }
    for(int i = 0; i < q; i++) {
        cin >> qc[i].first >> qc[i].second;
    }
    sort(qc, qc + q);
    for(int i = 1; i <= n; i++) {
        while(h < q && qc[h].first == i) {
            rh.push_back({qc[h].second, qc[h].second - qc[h].first + 1});
            h++;
        }
        for(int x = 0; x < rh.size(); x++) {
            if(rh[x].first < i) {
                 prs -= rh[x].second;
                 rh.erase(rh.begin() + x);
            }
        }
        prs += rh.size();
        k[i] = prs;
    }
    for(int i = 1; i <= n; i++) {
        iz7 = (iz7 + (k[i] * nc[i]) % d7) % d7;
        iz9 = (iz9 + (k[i] * nc[i]) % d9) % d9;
    }
    cout << iz7 % d7 << ' ' << iz9 % d9;
    return 0;
}
