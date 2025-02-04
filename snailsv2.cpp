#include <bits/stdc++.h>
using namespace std;

const int maxn = pow(10, 6) + 1;
bool mp[maxn];

int main () {
    int n, a, b, brt = 0;
    cin >> n;
    unordered_map <int, int> mp;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        if(a < 0 || b < 0)  continue;
        if(a + b + 1 != n) continue;
        if(!mp[a])  {
            brt++;
            mp[a] = true;
        }
    }
    cout << brt;
    return 0;
}
