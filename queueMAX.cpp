#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, t, x, l = 1, r = 0;
    cin >> n;
    deque <pair<int, int>> qu;
    for(int i = 0; i < n; i++) {
        cin >> t;
        if(t == 1) {
            cin >> x;
            r++;
            while(!qu.empty() && qu.back().first < x) {
                qu.pop_back();
            }
            qu.push_back({x, r});
            cout << qu.front().first << ' ';
        } else if(t == 2) {
            if(qu.front().second == l) {
                qu.pop_front();
            }
            l++;
            if(qu.empty()) {
                cout << -1 << ' ';
                continue;
            }
            cout << qu.front().first << ' ';
        }
    }
    return 0;
}
