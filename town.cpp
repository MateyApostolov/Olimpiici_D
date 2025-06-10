#include <bits/stdc++.h>
using namespace std;

const int maxn = 2 * pow(10, 5) + 1;
vector <pair<int, int>> graph[maxn];
bool vis[maxn];

int main () {
    int n, x, y, a, b;
    cin >> n >> x >> y;
    while(cin >> a >> b) {
        graph[a].push_back({b, 0});
        graph[b].push_back({a, 1});
    }
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qu;
    qu.push({x, 0});
    while(!qu.empty()) {
        pair<int, int> a = qu.top();
        qu.pop();
        for(auto b : graph[a.first]) {
            if(vis[b.first]) continue;
            qu.push({b.first, b.second + a.second});
            vis[b.first] = true;
        }
    }
    if(!vis[y]) cout << 'X';
    return 0;
}
