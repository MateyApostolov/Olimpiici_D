#include <bits/stdc++.h>
using namespace std;

const int maxm = pow(10, 8);
int brc[maxm];

int main () {
    int ar, t, hi = 0, w = 0, m = 0;
    vector <pair<int, int>> cust;
    while(cin >> ar >> t) {
        cust.push_back({ar, t});
    }
    sort(cust.begin(), cust.end());
    for(int x = cust[0].first; x < cust[0].first + cust[0].second; x++) {
        brc[x]++;
    }
    for(int i = 1; i < cust.size(); i++) {
        if(cust[i].first < cust[i - 1].first + cust[i - 1].second) {
            m += cust[i - 1].first + cust[i - 1].second - cust[i].first;
            cust[i].first = cust[i - 1].first + cust[i - 1].second;
        }
        for(int x = cust[i].first; x < cust[i].first + cust[i].second; x++) {
            brc[x]++;
        }
    }
    while(hi < 800) {
        if(hi == 720 && brc[hi] == 0) break;
        if(brc[hi] == 0) w++;
        hi++;
    }
    cout << w << ' ' << m;
    return 0;
}
