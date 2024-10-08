#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000001, maxbrp = 100000;
bool er[maxn];
int pr[maxbrp];
vector <int> prime;

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

void set_prime () {
    for(int i = 2; i < maxn; i++) {
        if(!er[i]) {
            prime.push_back(i);
        }
    }
}

int ng_del (int nc) {
    int ngd, i = 0;
    while(nc > 1) {
        if (!er[nc]) return nc;
        if(nc % prime[i] == 0) {
            ngd = prime[i];
        }
        while(nc % prime[i] == 0) {
            nc /= prime[i];
        }
        i++;
    }
    return ngd;
}

int main () {
    int n, r = -1, izl = 0, izr = -1, t;
    eratosten();
    set_prime();
///    for(int i = 0; i < 100; i++) cout << prime[i] << ' ';
    cin >> n;
    int nc[n];
    for(int i = 0; i < n; i++) {
        cin >> t; nc[i] = ng_del(t);
    }
    for(int i = 0; i < n; i++) cout << nc[i] << ' ';
    cout << '\n';
    for(int l = 0; l < n; l++) {
        while(r + 1 < n && pr[nc[r + 1]] == 0) {
            pr[nc[r + 1]]++;
            r++;
        }
        if(r - l > izr - izl) {
            izl = l;
            izr = r;
        }
        cout << "l = " << l << ", r = " << r << ", izl = " << izl << ", izr = " << izr << '\n';
        pr[nc[l]]--;
    }
    cout << ++izl << ' ' << ++izr;
    return 0;
}
