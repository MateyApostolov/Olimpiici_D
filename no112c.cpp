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
    int n, m, t, q, u, v;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) par[i] = i;
    for(int i = 0; i < m; i++) {
        cin >> t >> u >> v;
        if(t == 1) union_(u, v);
        else if(find_p(v) == find_p(u)) cout << "yes\n";
        else cout << "no\n";
    }a

    return 0;
}
