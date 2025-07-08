#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k, a, b, l;
    cin >> n >> m >> k;
    pair<int, int> tp[k + 1];
    for(int i = 1; i <= k; i++) cin >> tp[i].first;
    for(int i = 1; i <= k; i++) cin >> tp[i].second;
    map <int, bool> lines[k + 1];
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> l;
        lines[l][a] = true;
        lines[l][b] = true;
    }
    vector <pair<int, int>> graph[n + 1];
    for(int i = 1; i <= k; i++) {
        for(auto x : lines[i]) {
            for(auto y : lines[i]) {
                if(x.first >= y.first) {
                    graph[x.first].push_back({y.first, i});
                    graph[y.first].push_back({x.first, i});
                }
            }
        }
    }
    pair <int, int> dj[n + 1];
    for(int i = 0; i <= n; i++) dj[i] = {INT_MAX, INT_MAX};
    priority_queue <pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;
    dj[1] = {0, 0};
    pq.push({dj[1], 1});
    while(!pq.empty()) {
        int a = pq.top().second, dis = pq.top().first.first, t = pq.top().first.second;
        pq.pop();
        for(auto b : graph[a]) {
            int nd = dis + tp[b.second].second, nt = t + tp[b.second].first;
            if(nd < dj[b.first].first || (nd == dj[b.first].first && nt < dj[b.first].second)) {
                dj[b.first].first = nd;
                dj[b.first].second = nt;
                pq.push({{nd, nt}, b.first});
            }
        }
    }
    cout << dj[n].first << ' ' << dj[n].second;
    return 0;
}
