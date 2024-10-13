#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, num;
    cin >> n;
    vector <pair <int, int>> c;
    vector <int> pn;
    for(int i1 = 0; i1 < 3; i1++) {
        for(int i2 = 0; i2 < n; i2++) {
            cin >> num;
            c.push_back(make_pair(num, i1));
        }
    }
    sort(c.begin(), c.end());
    for(int l = 0; l < c.size();) {
        int br[3] = {};
        int r = l;
        while(r < c.size() && c[r].first == c[l].first) {
            r++;
        }
        for(int i = l; i < r; i++) {
            br[c[i].second]++;
            if(br[0] > 0 && br[1] > 0 && br[2] > 0) {
                pn.push_back(c[i].first);
            }
        }
        l = r;
    }
    cout << pn[0] << ' ';
    for(int i = 1; i < pn.size(); i++) {
        if(pn[i] != pn[i - 1]) {
            cout << pn[i] << ' ';
        }
    }
    return 0;
}
