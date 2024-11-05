#include <bits/stdc++.h>
#define int long long
using namespace std;

int br[20], md[20];

int d(int a) {
    for(int i = 1; i <= 17; i++) {
        if(br[i] >= a) return i;
    }
    return -1;
}

int dn (int num) {
    int br = 0;
    while(num > 0) {
        num /= 10;
        br++;
    }
    return br;
}

int cr (int a, int brc) {
    if(a > brc - 1) {
        a -= brc - 1;
        int da = d(a);
        a -= br[da - 1];
        int nc = md[da] + (a - 1) / da;
        int c = (a - 1) % da;
        return to_string(nc)[c] - '0';
    } else {
        a = brc - a + 1;
        int da = d(a);
        a -= br[da - 1];
        int nc = md[da] + (a - 1) / da;
        int c = (a - 1) % da;
        string s = to_string(nc);
        reverse (s.begin(), s.end());
        return s[c] - '0';
    }
}

main () {
    long long n, nums = 9, a, b;
    cin >> n >> a >> b;
    for(int i = 1; i <= 17; i++) {
        br[i] = br[i - 1] + nums * i;
        nums *= 10;
    }
    md[1] = 1;
    for(int i = 2; i <= 17; i++) {
        md[i] = md[i - 1] * 10;
    }
    int brn = dn(n), brc = br[brn - 1] + (n - md[brn] + 1) * brn;
    cout << cr(a, brc) - cr(b, brc);
    return 0;
}

