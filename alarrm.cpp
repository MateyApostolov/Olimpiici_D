#include <bits/stdc++.h>
using namespace std;

const int maxn = 9;
int a, b, x, y, n, bestway = 10e9, way = 0;
pair <int, int> wk[maxn];
vector <int> wk_idx;
bool used[maxn];

int raz (pair<int, int> k, pair<int, int> xy) {
    return abs(k.first - xy.first) + abs(k.second - xy.second);
}

void rec_way () {
    if(wk_idx[0] == n) {
        for(int i = 0; i + 1 < n; i++) {
            way += raz(wk[wk_idx[i]], wk[wk_idx[i + 1]]);
        }
        way += raz(make_pair(x, y), wk[wk_idx[0]]);
        way += raz(make_pair(x, y), wk[wk_idx[wk_idx.size() - 1]]);
        if(bestway > way) {
            bestway = way;
            way = 0;
        }
    }
    for(int i = 0; i < n; i++) {
        if(used[i]) continue;
        wk_idx.push_back(i);
        used[i] = true;
        rec_way();
        wk_idx.pop_back();
        used[i] = false;
    }
}

int main () {
    cin >> a >> b >> x >> y >> n;
    for(int i = 0; i < n; i++) {
        cin >> wk[i].first >> wk[i].second;
    }
    rec_way();
    cout << bestway;
    return 0;
}




