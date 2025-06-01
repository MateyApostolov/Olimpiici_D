#include <bits/stdc++.h>
using namespace std;

const int maxn = pow(10, 5) + 1;
int inc[maxn];
vector <int> graph[maxn];

int main () {
    int n, m, x, y;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
        inc[y]++;
    }
    priority_queue <int, vector<int>, greater<int>> bfs;
    vector <int> ans;
    for(int x = 1; x <= n; x++) {
        if(inc[x] == 0) bfs.push(x);
    }
    while(!bfs.empty()) {
        int x = bfs.top();
        bfs.pop();
        ans.push_back(x);
        for(auto y : graph[x]) {
            inc[y]--;
            if(inc[y] == 0) bfs.push(y);
        }
    }
    if(ans.size() != n) {
        cout << "Sandro fails.";
        return 0;
    }
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}

