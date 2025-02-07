#include  <bits/stdc++.h>
using namespace std;

int main () {
    int n, nok = 1;
    cin >> n;
    int nc[n];
    map <int, int> mp;
    vector <pair<int, int>> prime_del = {{2, 0}, {3, 0}, {5, 0}, {7, 0}, {11, 0}, {13, 0}, {17, 0}, {23, 0}, {29, 0}, {31, 0}, {37, 0}, {41, 0}};
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
        mp[nc[i]]++;
    }
    for(pair<int, int> x : mp) {
        int hi = 0;
        while(x.first > 1) {
            while(x.first % prime_del[hi].first == 0) {
                x.first /= prime_del[hi].first;
                prime_del[hi].second++;
            }
            prime_del[hi].second *= x.second;
            hi++;
        }
    }
    for(int i = 0; i < prime_del.size(); i++) {
        if(prime_del[i].second % 2 != 0) nok *= pow(prime_del[i].first, prime_del[i].second / 2 + 1);
        else nok *= pow(prime_del[i].first, prime_del[i].second / 2);
    }
    cout << nok;
    return 0;
}
