#include <bits/stdc++.h>
using namespace std;

const int maxn = 2 * pow(10, 6) + 1;
bool zdr[maxn];
int brd[maxn];

int brr (int num, int del) {
    int br = 0;
    while(num % del == 0) {
        num /= del;
        br++;
    }
    return br;
}

void eratosten () {
    for(int d = 2; d <= maxn; d++) {
        if(zdr[d]) continue;
        for(int h = d * d; h <= maxn; h += d) {
            zdr[h] = true;
        }
    }
    return;
}

int main () {
    eratosten();
    int n, r = -1, op = 0;
    cin >> n;
    int nc[n];
    vector <int> prd;
    for(int i = 0; i < n; i++) cin >> nc[i];
    for(int i = 2; i <= maxn; i++) {
        if(!zdr[i]) prd.push_back(i);
    }
    for(int i = 0; i < prd.size(); i++) {
        for(int l = 0; l < n;) {
            int maxbr = 0;
            while(r + 1 < n && nc[r] % prd[i] == 0) {
                r++;
                maxbr = max(maxbr, brr(nc[r], prd[i]));
            }
            op += maxbr;
            l++;
        }
    }
    cout << op;
    return 0;
}
