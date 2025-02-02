#include <bits/stdc++.h>
using namespace std;

const int maxn = 3 * pow(10, 6) + 1;
int a[maxn], c[maxn];
bool mp[maxn];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, br3 = 0;
    cin >> n;
    int nc[n];
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
        mp[nc[i]] = true;
    }
    for(int i = 0; i < n; i++) {
        for(int x = 2 * nc[i]; x < maxn; x += nc[i]) {
            if(!mp[x]) continue;
            c[x]++;
            a[nc[i]]++;
        }
    }
    for(int i = 0; i < n; i++) {
        br3 += a[nc[i]] * c[nc[i]];
    }
    cout << br3;
    return 0;
}
