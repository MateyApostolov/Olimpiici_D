#include <bits/stdc++.h>
using namespace std;

const int maxn = 10e5 + 1;
int par[maxn], sz[maxn], cnt;
bool stay[maxn];
vector<pair<int, int>> thr;
vector <int> qc;
vector <int> ans;

int find_p(int u) {
    if(par[u] == u) return u;
    return par[u] = find_p(par[u]);
}

void union_(int u, int v) {
    u = find_p(u);
    v = find_p(v);
    if(u == v) return;
    cnt--;
    if(sz[u] < sz[v]) swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, q, u, v, t;
    cin >> n >> m;
    cnt = n;
    for(int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        thr.push_back({u, v});
    }
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> t;
        t--;
        qc.push_back(t);
        stay[t] = true;
    }
    for(int i = 0; i < m; i++) {
        if(!stay[i]) union_(thr[i].first, thr[i].second);
    }
    for(int i = qc.size() - 1; i >= 0; i--) {
        ans.push_back(cnt);
        union_(thr[qc[i]].first, thr[qc[i]].second);
    }
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
    return 0;
}
