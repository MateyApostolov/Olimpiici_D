#include <iostream>
using namespace std;

const int maxc = 1000000;
int brnc[maxc], pref[maxc];

void eratosten () {
    for(int d = 2; d < maxc; d++) {
        if(brnc[d] > 0) continue;
        for(int k = d; k < maxc; k += d) {
            brnc[k]++;
        }
    }
}

int main () {
    int t, a, b;
    cin >> t;
    eratosten();
    for(int i = 1; i < maxc; i++) {
        if(brnc[i] == 3) pref[i] = pref[i - 1] + 1;
        else pref[i] = pref[i - 1];
    }
    for(int i = 0; i < t; i++) {
        cin >> a >> b;
        cout << pref[b] - pref[a - 1] << '\n';
    }

    return 0;
}
