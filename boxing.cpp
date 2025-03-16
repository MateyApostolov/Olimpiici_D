#define _GLIBCXX_FILESYSTEM
#include <bits/stdc++.h>
using namespace std;

const int maxc = pow(10, 7) + 1;
long long pref[maxc];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, k, n1, n2, x, y, z, m, brd = 0, j, sb;
    cin >> n >> k >> n1 >> n2 >> x >> y >> z >> m;
    long long seq[n + 2], b[n + 3] = {};
    seq[0] = n1;
    seq[1] = n2;
    for(int i = 2; i <= n; i++) {
        seq[i] = (seq[i - 2] * x + seq[i - 1] * y + z) % m;
    }
    for(long long i = 1, j = 0, sb = 0; i <= n;) {
        while(j + 1 <= n && sb < k) {
            sb += seq[j++];
        }
        if(sb >= k) b[i] = j;
        else b[i] = n + 1;
        sb -= seq[i++];
    }
    b[n + 2] = b[n + 1] = n + 1;
    for(int l = 1; l <= n; l++) {
        int mb = b[l];
        int r = b[mb + 1];
        brd += n - r + 1;
    }
    cout << brd;
    return 0;
}


