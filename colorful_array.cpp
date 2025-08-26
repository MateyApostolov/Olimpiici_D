#include <bits/stdc++.h>
using namespace std;

const int maxn = 2 * 10e5 + 1;
int n, q, l, r, c;
int col[maxn], par[maxn], sz[maxn];

int find_p(int p) {
    if(p == n) return 0;
    return p + 1;
}

void union_(int l, int r) {
    for(int i = l; i <= r; i++) {
        i = find_p(i);
    }
}

int main () {
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
    for(int i = 0; i < q; i++) {
        cin >> l >> r >> c;

    }

    return 0;
}
