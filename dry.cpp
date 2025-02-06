#include <bits/stdc++.h>
using namespace std;

int main  () {
    int n, u, v, sum = 0;
    cin >> n >> u >> v;
    int h[n];
    for(int i = 0; i < n; i++) cin >> h[i];
    for(int i = 1; i < n - 1; i++) {
        int lm = h[i], rm = h[i];
        for(int x = 0; x < i; x++) lm = max(lm, h[x]);
        for(int x = i + 1; x < n; x++) rm = max(rm, h[x]);
        h[i] = min(lm, rm);
    }
    for(int i = 1; i < n; i++) {
        sum += min(h[i], h[i - 1]);
    }
    cout << sum * u * v;
    return 0;
}
