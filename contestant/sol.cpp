#include "flowers.h"
#include <bits/stdc++.h>
using namespace std;

void play(int n) {
    vector <int> col(n);
    vector <int> fir_occ(n);
    col[0] = 1;
    for(int i = 0; i < n; i++) {
        int l = 0, r = fir_occ.size(), ans = -1;
        while(l <= r) {
            int mid = (l + r) / 2;
            vector <int> qu = fir_occ;
            qu.resize(mid + 1);
            qu.push_back(i);
            int quest = count_different(qu);
            if(quest == qu.size()) {
                l = mid + 1;
            } else {
                ans = mid;
                r = mid - 1;
            }
        }
        if(ans == -1) {
            fir_occ.push_back(i);
            col[i] = fir_occ.size();
        } else {
            col[i] = col[fir_occ[ans]];
        }
    }
    submit_colours(col);
}
