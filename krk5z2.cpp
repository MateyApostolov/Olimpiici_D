#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, k, kc;
    cin >> n >> k;
    vector <long long> pc;
    for(int i1 = 0; i1 < k; i1++) {
        cin >> kc;
        bool isr = false;
        for(int i2 = 0; i2 < pc.size(); i2++) {
            if(kc == pc[i2]) {
                isr = true;
                break;
            }
        }
        if(!isr) {
            pc.push_back(kc);
            n--;
        }
    }
    cout << n;
    return 0;
}
