#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000001, maxbrp = 1000001;
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
        if(!er[nc]) return nc;
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
    int n, r = -1, izl = 0, izr = 0;
    cin >> n;
    int nc[n];
    eratosten();
    set_prime();
    int h;
    for(int i = 0; i < n; i++) {
        cin >> h;
        nc[i] = ng_del(h);
    }
///    for(int i = 0; i< n;i++) cout << nc[i]<<' ';
    for(int l = 0; l < n; l++) {
        while(r + 1 < n && pr[nc[r + 1]] == 0) {
            pr[nc[r + 1]]++;
            r++;
        }
        if(r - l + 1 > izr - izl + 1) {
            izl = l;
            izr = r;
        }
        pr[nc[l]]--;
    }
    cout << izl + 1 << ' ' << izr + 1;
    return 0;
}
