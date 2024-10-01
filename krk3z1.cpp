#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000000;
int nc[maxn];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, br = 0, l = 0, r = 0;
    long long s;
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
    }
    long long sum = nc[0];
    while(r < n && l < n - 1) {
        while(r + 1 < n && sum < s) {
            r++;
            sum = sum + nc[r];
            ///cout << "br = " << br << ", sum = " << sum << ", l = " << l << ", r = " << r << '\n';
        }
        if(sum == s) {
            br++;
            sum = sum - nc[l];
            l++;
           ///cout << "br = " << br << ", sum = " << sum << ", l = " << l << ", r = " << r << '\n';
            continue;
        }
        while(l + 1 <= r && sum > s) {
            sum = sum - nc[l];
            l++;
            ///cout << "br = " << br << ", sum = " << sum << ", l = " << l << ", r = " << r << '\n';
        }
    }
    cout << br;
    return 0;
}
