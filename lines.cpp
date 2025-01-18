#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, m, x, y, res;
    cin >> n >> m >> x >> y;
    res = (x - 1) * m;
    if(x % 2 != 0) res += (y - 1);
    else res += m - y;
    cout << res;
    return 0;
}
