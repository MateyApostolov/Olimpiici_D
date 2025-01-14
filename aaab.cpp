#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, i = 0, br3 = 0;
    cin >> n;
    while(i < pow(2, n)) {
        vector <int> nc;
        int h = i, h2 = 0, brs = 0;
        while(h2 < n) {
            nc.push_back(h % 2);
            if(nc.size() > 1) {
                if((nc[nc.size() - 1] == 0 && nc[nc.size() - 2] == 0) || (nc[nc.size() - 1] == 0 && nc[nc.size() - 2] == 1)) brs++;
            }
            h /= 2;
            h2++;
        }
        if(brs % 3 == 0) br3++;
        i++;
    }
    cout << br3;
    return 0;
}
