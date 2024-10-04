#include <bits/stdc++.h>
using namespace std;

int const maxn = pow(10, 6) + 1;
bool er[maxn];
vector <int> primen;

void eratosten () {
    for(int d = 2; d * d < maxn; d++) {
        if(!er[d]) {
            for(int h = d * d; h < maxn; h += d) {
                er[h] = true;
            }
        }
    }
    return;
}

void set_p () {
    primen.push_back(1);
    for(int i = 2; i < maxn; i++) {
        if(!er[i]) {
            primen.push_back(i);
        }
    }
    return;
}

int main () {
    int n, k, r = -1, bigd = 1;
    cin >> n >> k;
    int nc[n];
    eratosten ();
    set_p ();
    vector <vector <int>> rc(n);
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
    }
    /*for(int i = 0; i < primen.size(); i++) {
        cout << primen[i] << " ";
    }
    return 0;*/
    for(int l = 0; l < n - k + 1; l++) {
        bool isd = true;
        int h = 0;
        while(h < primen.size() && isd == true) {
            for(int i = l; i < l + k; i++) {
                cout << nc[i] << ' ';
                if(nc[i] % primen[h] != 0) {
                    isd = false;
                }
            }
            if(isd) {
                bigd = max(primen[h], bigd);
            }
            h++;
            cout << '\n' << primen[h] << '\n';
        }

    }
    cout << bigd;
    return 0;
}
