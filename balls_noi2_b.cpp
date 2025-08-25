#include <bits/stdc++.h>
using namespace std;

int cnt_col = 0;
unordered_map <int, int> par, sz;

int find_p(int u) {
    if(par[u] == 0) return u;
    return par[u] = find_p(par[u]);
}

void union_(int u, int v) {
    u = find_p(u);
    v = find_p(v);
    if(u == v) return;
    cnt_col++;
    if(sz[v] == 0) sz[v] = 1;
    if(sz[u] == 0) sz[u] = 1;
    if(sz[u] < sz[v]) swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
}

int main () {
    int n, m, u, v;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        union_(u, v);
    }
    cout << n - cnt_col;
    return 0;
}
