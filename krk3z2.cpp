#include <bits/stdc++.h>
using namespace std;

const int maxk = pow(10, 4) * 4 + 1;
int rr[maxk], n, k;

bool check_r () {
    for(int i = 0; i < k; i++) {
        if(rr[i] == 0) {
            return false;
        }
    }
    return true;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    int r = -1, minr = n, minl = 1, nc, brc;
    bool ch = false;
    map <int, vector<int>> mp;
    for(int i1 = 0; i1 < k; i1++) {
        cin >> brc;
        for(int i2 = 0; i2 < brc; i2++) {
            cin >> nc;
            mp[nc].push_back(i1);
        }
    }
    vector <pair<int, vector<int>>> vc;
    for(auto x : mp) {
        vc.push_back({x.first, x.second});
    }
    for(int l = 0; l < vc.size(); l++) {
        while(r + 1 < vc.size() && !ch) {
            for(int i = 0; i < vc[r + 1].second.size(); i++) {
                rr[vc[r + 1].second[i]]++;
            }
            ch = check_r();
            r++;
        }
        if(ch && vc[r].first - vc[l].first < minr - minl) {
            minr = vc[r].first;
            minl = vc[l].first;
        }
        if(r == n && !ch) break;
        for(int i = 0; i < vc[l].second.size(); i++) {
            rr[vc[l].second[i]]--;
        }
        ch = check_r();
    }
    cout << minl << ' ' << minr;
    return 0;
}
