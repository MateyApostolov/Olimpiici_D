#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000000, maxbrp = 100000;
bool er[maxn], pr[maxbrp];
vector <int> prime;

void eratosten () {
    for(int d = 2; d < maxn; d++) {
        if(!er[d]) {
            for(int h = d + d; h < maxn; h += d) {
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
    int ngd = 2;
    for(int i = 0; i < prime.size(); i++) {
        if(nc % prime[i] == 0) {
            ngd = prime[i];
        }
        while(nc % prime[i] == 0) {
            nc /= prime[i];
        }
    }
    return ngd;
}

int main () {
    int n, r = -1, izl = 0, izr = 0;
    cin >> n;
    int nc[n];
    eratosten();
    set_prime();
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
    }
    for(int l = 0; l < n; l++) {
        while(r + 1 < n && !pr[ng_del(nc[r + 1])]) {
            pr[ng_del(nc[r + 1])] = true;
            r++;
        }
        if(r - l + 1 > izr - izl + 1) {
            izl = l;
            izr = r;
        }
        l++;
        pr[maxbrp] = {};
    }
    cout << izl << ' ' << izr;
    return 0;
}
