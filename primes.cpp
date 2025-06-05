#include <bits/stdc++.h>
using namespace std;

const int maxn = pow(10, 6) + 1;
int del[maxn];

void eratosten () {
    for(long long d = 2; d < maxn; d++) {
        if(del[d] == -1) continue;
        for(long long h = d * d; h < maxn; h += d) {
            del[h] = -1;
        }
    }
}

int main () {
    eratosten();
    int a, b, hi = -1, prl = -1, prr = -1, maxk = -1, prc = -1;
    cin >> a >> b;
    vector <int> prime;
    for(int i = 2; i < maxn; i++) {
        if(del[i] == 0) {
            prime.push_back(i);
            del[i] = prime.size();
        }
    }
    for(int i = a; i <= b; i++) {
        if(del[i] != -1) {
            hi = del[i] - 1;
            break;
        }
    }
    if(hi == -1) {
        cout << "no prime";
        return 0;
    }
    while(prime[hi] <= b) {
        int r = -1, sum = 0, hl = -1, hr = -1;
        for(int l = 0; l <= hi; l++) {
            while(r + 1 <= hi && sum + prime[r + 1] <= prime[hi]) {
                r++;
                sum += prime[r];
            }
            if(sum == prime[hi]) {
                hl = l;
                hr = r;
                break;
            }
            sum -= prime[l];
        }
        if(hr - hl + 1 > maxk) {
            maxk = hr - hl + 1;
            prl = hl;
            prr = hr;
            prc = prime[hi];
        }
        hi++;
    }
    if(maxk == -1) {
        cout << "no prime";
        return 0;
    }
    cout << prc << ' ' << maxk << '\n';
    for(int i = prl; i <= prr; i++) cout << prime[i] << ' ';
    return 0;
}
