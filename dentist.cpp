#include <bits/stdc++.h>
using namespace std;

int main () {
    vector <pair<int, int>> pac;
    int c1, c2, pr = 0;
    while(cin >> c1) {
        cin >> c2;
        pac.push_back({c1, c2});
    }
    sort(pac.begin(), pac.end());
    for(int i = 0; i < pac.size() - 1; i++) {
        pr += pac[i].second;
        pr = max(0, pr - (pac[i + 1].first - pac[i].first));
    }
    pr += pac[pac.size() - 1].second;
    cout << pr;
    return 0;
}
