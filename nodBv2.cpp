#include <bits/stdc++.h>
using namespace std;

int main () {
    unsigned long long n, pr = 2, prp = 1, cur;
    cin >> n;
    for(int i = 2; i <= n; i++) {
        cur = pr + prp;
        prp = pr;
        pr = cur;
    }
    cout << prp << ' ' << pr;
    return 0;
}
