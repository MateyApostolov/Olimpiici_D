#include <bits/stdc++.h>
using namespace std;

const int maxn = pow(10, 5) + 1;
vector <int> graph[maxn];
vector <int> st, cyc;
int vis[maxn];

void dfs (int x) {
    vis[x] = 1;
    st.push_back(x);
    for(auto y : graph[x]) {
        if(vis[y] == 2) continue;
        if(vis[y] == 0) dfs(y);
        else if(cyc.empty()){
            for(int i = st.size() - 1; i >= 0; i--) {
                cyc.push_back(st[i]);
                if(st[i] == y) break;
            }
            reverse(cyc.begin(), cyc.end());
        }
    }
    vis[x] = 2;
    st.pop_back();
    return;
}


int main () {
    int n, m, x, y;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(int x = 1; x <= n; x++) {
        dfs(x);
        if(cyc.size() - 1 < 2) continue;
        cout << cyc.size() + 1 << '\n';
        for(int i = 0; i < cyc.size(); i++) cout << cyc[i] << ' ';
        cout << cyc[0];
        return 0;
    }
    cout << "IMPOSSIBLE";
    return 0;
}
