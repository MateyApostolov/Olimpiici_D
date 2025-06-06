#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, br = 0, brh = -1, a;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a;
        if(a == brh) br++;
        else {
            if(br > 0) br--;
            else {
                brh = a;
                br = 1;
            }
        }
    }
    br = 0;
    for(int i = 0; i < n; i++) {
        cin >> a;
        if(a == brh) br++;
    }
    cout << min(n - 1, 2 * (n - br));
    return 0;
}
