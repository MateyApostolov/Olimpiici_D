#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, m, hd, brd = 0;
    cin >> n >> m;
    pair <int, int> det[n];
    for(int i = 0; i < n; i++) cin >> det[i].first >> det[i].second;
    sort(det, det + n);
    hd = det[0].second;
    for(int i = 1; i < n; i++) {
        if(det[i].second >= det[i - 1].second) hd = det[i].second;
        else {
            brd += hd - det[i].second;
            hd = det[i].second;
        }
    }
    brd += hd;
    cout << brd;
    return 0;
}
