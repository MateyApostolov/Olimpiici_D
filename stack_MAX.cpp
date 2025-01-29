#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, t, x, maxc = 0;
    cin >> n;
    stack <pair<int, int>> st;
    for(int i = 0; i < n; i++) {
        cin >> t;
        if(t == 1) {
            cin >> x;
            maxc = max(maxc, x);
            st.push({x, maxc});
            cout << maxc << ' ';
        } else if(t == 2) {
            st.pop();
            if(st.empty()) {
                cout << -1 << ' ';
                maxc = 0;
                continue;
            }
            maxc = st.top().second;
            cout << maxc << ' ';
        }
    }
    return 0;
}
