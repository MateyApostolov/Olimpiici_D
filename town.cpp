#include <bits/stdc++.h>
using namespace std;

const int maxn = 2 * pow(10, 5) + 1;
vector <pair<int, int>> graph[maxn];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x, y, a, b;
    cin >> n >> x >> y;
    int ra[n + 1];
    for(int i = 0; i <= n; i++) ra[i] = INT_MAX;
    while(cin >> a >> b) {
        graph[a].push_back({b, 0});
        graph[b].push_back({a, 1});
    }
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qu;
    qu.push({0, x});
    ra[x] = 0;
    while(!qu.empty()) {
        int d = qu.top().first, idx = qu.top().second;
        qu.pop();
        if(d > ra[idx]) continue;
        for(auto b : graph[idx]) {
            int nidx = b.first, nd = b.second + d;
            if(nd < ra[nidx]) {
                qu.push({nd, nidx});
                ra[nidx] = nd;
            }
        }

    }
    if(ra[y] == INT_MAX) cout << 'X';
    else cout << ra[y];
    return 0;
}
