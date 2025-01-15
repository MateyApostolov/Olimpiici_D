#include <bits/stdc++.h>
using namespace std;

int main () {
    double nc, pr = 0, br = 0, maxbr = 0;
    do{
        cin >> nc;
        if(nc >= pr) br++;
        else {
            maxbr = max(maxbr, br);
            br = 1;
        }
        pr = nc;
    } while(nc != 0);
    cout << maxbr;
    return 0;
}

