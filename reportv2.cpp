#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int nc[n];
    stack <int> idx;
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
        while(!idx.empty() && nc[i] <= nc[idx.top()]) idx.pop();
        if(idx.empty()) cout << 0 << ' ';
        else cout << idx.top() + 1 << ' ';
        idx.push(i);

    }

    return 0;
}
