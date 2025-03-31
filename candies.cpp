#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, q, idx = 0;
    cin >> n >> q;
    pair <int, int> qc[q];
    priority_queue <int> en;
    int nc[n + 1] = {};
    for(int i = 0; i < q; i++) {
        cin >> qc[i].first >> qc[i].second;
    }
    sort(qc, qc + q);
    for(int i = 1; i <= n; i++) {
        while(idx < q && qc[idx].first == i) {
            en.push(qc[idx].second * -1);
            idx++;
        }
        nc[i] += en.size();
        while(!en.empty() && en.top() * -1 == i) en.pop();
    }
    for(int i = 1; i <= n; i++) cout << nc[i] << ' ';

    return 0;
}
