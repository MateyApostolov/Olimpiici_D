#include <bits/stdc++.h>
using namespace std;

const int maxx = 300000;
int used[maxx];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, t, x;
    cin >> n;
    queue <int> qu;
    for(int i = 0; i < n; i++) {
        cin >> t >> x;
        if(t == 1) qu.push(x);
        else {
            used[x] = true;
            while(!qu.empty() && used[qu.front()]) {
                used[qu.front()] = true;
                qu.pop();
            }
        }
        if(qu.empty()) cout  << -1 << ' ';
        else cout  << qu.front()  << ' ' ;
    }


    return 0;
}
