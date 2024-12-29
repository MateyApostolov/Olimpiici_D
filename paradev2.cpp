#include <bits/stdc++.h>
using namespace std;

int br;

void rec_s (int d, int p) {
    if(p == d / 2 + 1) return;
    br++;
    if(p > d / 2 + 1) p -= d / 2 + 1;
    d /= 2;
    rec_s(d, p);
}

int main () {
    int n, p, d;
    cin >> n >> p;
    d = pow(2, n) - 1;
    if(p > d) {
        cout << 0;
        return 0;
    }
    rec_s(d, p);
    cout << char(br + 'a');
    return 0;
}
