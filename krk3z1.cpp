#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000000;
int nc[maxn];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, br = 0, r = -1;
    long long s;
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
    }
    long long sum = 0;
    for(int l = 0; l < n; l++) {
        while(r + 1 < n && sum + nc[r + 1] <= s) {
            r++;
            sum = sum + nc[r];
            ///cout << "br = " << br << ", sum = " << sum << ", l = " << l << ", r = " << r << '\n';
        }
        if(sum == s) {
            br++;
        }
        sum = sum - nc[l];
    }
    cout << br;
    return 0;
}
