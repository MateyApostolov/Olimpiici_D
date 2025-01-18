#include <bits/stdc++.h>
using namespace std;

int main () {
    long long q, s, f;
    cin >> q;
    for(int i = 1; i <= q; i++) {
        cin >> s >> f;
        long long sum = (f - s + 1) / 9 * 45, ost = (f - s + 1) % 9, beg = s % 9;
        for(int x = 0; x < ost; x++) {
            if(beg != 0) sum += beg;
            else sum += 9;
            beg = (beg + 1) % 9;
        }

        cout << sum << '\n';
    }

    return 0;
}
