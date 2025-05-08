#include <bits/stdc++.h>
using namespace std;

const int maxn = 2 * pow(10, 6) + 1;
bool zdr[maxn];
int ngd[maxn];
map <int, int> del, brd;

void eratosten () {
    for(long long d = 2; d <= maxn; d++) {
        if(zdr[d]) continue;
        ngd[d] = d;
        for(long long h = d * d; h <= maxn; h += d) {
            zdr[h] = true;
            ngd[h] = d;
        }
    }
    return;
}

void can (int num) {
    while(num > 1) {
        del[ngd[num]]++;
        num /= ngd[num];
    }
    return;
}

int main () {
    eratosten();
    int n, op = 0;
    cin >> n;
    int nc[n];
    for(int i = 0; i < n; i++) cin >> nc[i];
    can(nc[0]);
    for(auto x : del) {
        op += x.second;
    }
    brd = del;
    for(int i = 1; i < n; i++) {
        del.clear();
        can(nc[i]);
        for(auto x : del) {
            if(brd[x.first] < x.second) {
                op += x.second - brd[x.first];
            }
        }
        brd = del;
    }
    cout << op;
    return 0;
}
