#include <bits/stdc++.h>
using namespace std;

const int maxn = 10e3 + 1;
int par[maxn];

int find_p(int u) {
    if(par[u] == u) return u;
    return par[u] = find_p(par[u]);
}

void union_(int u, int v) {
    u = find_p(u);
    v = find_p(v);
    if(u == v) return;
    par[u] = v;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, q, u, v;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) par[i] = i;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        union_(u, v);
        find_p(v);
    }
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> u >> v;
        if(find_p(u) == find_p(v)) cout << 1;
        else cout << 0;
    }

    return 0;
}
