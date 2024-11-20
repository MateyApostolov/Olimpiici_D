#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, k;
    cin >> n >> k;
    int sc[n];
    for(int i = 0; i < n; i++) {
        cin >> sc[i];
    }
    vector <pair<int, pair<int, int>>> rs;
    for(int i1 = 0; i1 < n - 1; i1++) {
        for(int i2 = i1 + 1; i2 < n; i2++) {
            rs.push_back({abs(sc[i1] - sc[i2]), {sc[i1], sc[i2]}});
        }
    }
    sort(rs.begin(), rs.end());
    cout << rs[k - 1].second.first << ' ' << rs[k - 1].second.second;
    return 0;
}
