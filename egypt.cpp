#include <bits/stdc++.h>
using namespace std;

int main () {
    int z, x, y  = INT_MAX;
    cin >> z;
    for(x = z + 1; x < y; x++) {
        y = (x * z) / (x - z);
        if((x * z) % (x - z) == 0) {
            if(y > x) cout << x << ' ' << y << '\n';
        }
    }
    return 0;
}
