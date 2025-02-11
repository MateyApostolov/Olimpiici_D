#include  <bits/stdc++.h>
using namespace std;

bool used[43];

int main () {
    long long n, nok = 1, nc, c = 1;
    cin >> n;
    vector <pair<int, int>> prime_del = {{2, 0}, {3, 0}, {5, 0}, {7, 0}, {11, 0}, {13, 0}, {17, 0}, {19, 0}, {23, 0}, {29, 0}, {31, 0}, {37, 0}, {41, 0}};
    for(int i = 0; i < n; i++) {
        cin >> nc;
        if(!used[nc]) {
            nok = nok * nc / __gcd(nok, nc);
            used[nc] = true;
        }
    }
    int hi = 0;
    while(nok > 1) {
        while(nok % prime_del[hi].first == 0) {
            nok /= prime_del[hi].first;
            prime_del[hi].second++;
        }
        hi++;
    }
    for(int i = 0; i < prime_del.size(); i++) {
        c *= pow(prime_del[i].first, prime_del[i].second / 2 + prime_del[i].second % 2);
    }
    cout << c;
    return 0;
}
