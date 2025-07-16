#include <bits/stdc++.h>
using namespace std;

const int maxn = pow(10, 6) + 1;
int m[maxn];
vector <int> kc;

int c (int sum) {
    if(sum < 0) return -1;
    if(sum == 0) return 0;
    if(m[sum] != 0) return m[sum];
    int br = -1;
    for(auto x : kc) {
        int h = c(sum - x);
        if(h == -1) continue;
        if(br == -1) br = h + 1;
        else br = min(br, h + 1);
    }
    m[sum] = br;
    return br;
}

int main () {
    int n, k, h;
    cin >> n >> k;
    for(int i = 0; i < k; i++) {
        cin >> h;
        kc.push_back(h);
    }
    cout << c(n);
    return 0;
}
