#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, k;
    cin >> n >> k;
    string s;
    stringstream ss;
    int minr[k], maxr[k] = {};
    getline(cin, s);
    int li = n, ri = 0;
    for(int i = 0; i < k; i++) {
        minr[i] = n;
        getline(cin, s);
        ss << s;
        int nc;
        while(ss >> nc) {
            minr[i] = min(nc, minr[i]);
            maxr[i] = max(nc, maxr[i]);
        }
        li = min(li, minr[i] )
        ss.clear();
    }
/*    for(int i = 0; i < k; i++) {
        cout << minr[i] << ' ' << maxr[i] << '\n';
    }
*/

}
