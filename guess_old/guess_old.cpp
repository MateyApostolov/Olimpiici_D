#include "guess_old.h"
#include <bits/stdc++.h>
using namespace std;

int find_number(int r) {
    int l = 1, ans = 0;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(!smaller(mid)) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}


