#include <bits/stdc++.h>
using namespace std;

const int maxn = 2 * pow(10, 5) + 1;
vector <pair<int, int>> graph[maxn];
int points[maxn];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k, a, b, p, t;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) points[i] = INT_MAX;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> p >> t;
        graph[a].push_back({b, t - p});
        graph[b].push_back({a, t - p});
    }
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qu;
    qu.push({0, 1});
    points[1] = 0;
    while(!qu.empty()) {
        int a = qu.top().second, p = qu.top().first;
        qu.pop();
        for(auto b : graph[a]) {
            int ha = b.first, hp = b.second;
            if(points[ha] > p + hp) {
                qu.push({p + hp, ha});
                points[ha] = p + hp;
            }
        }
    }
    cout << k - points[n];
    return 0;
}
