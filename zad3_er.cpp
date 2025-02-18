#include <bits/stdc++.h>
using namespace std;

const int maxc = pow(10, 6) + 1;
int prime[maxc];

void eratosten () {
    for(int d = 2; d <= maxc; d++) {
        if(prime[d] != 0) continue;
        for(int h = d; h <= maxc; h += d) {
            if(prime[h] == 0) {
                prime[h] = d;
            }
        }
    }
    return;
}

int main () {
    int n;
    cin >> n;
    eratosten();
    vector <int> kan;
    while(n > 1) {
        kan.push_back(prime[n]);
        n /= prime[n];
    }
    for(int i = 0; i < kan.size(); i++) {
        cout << kan[i] << ' ';
    }
    return 0;
}

