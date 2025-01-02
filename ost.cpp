#include <bits/stdc++.h>
using namespace std;

const int maxn = pow(10, 5);
long long n, nc[maxn];
vector <pair<int, int>> dwc;

bool equal_ost(int num) {
    for(int i = 0; i < dwc.size(); i++) {
        if(dwc[i].first % num != dwc[i].second % num) return false;
    }
    return true;
}

int br_del (long long num) {
    double koren = sqrt(num);
    int brd = 0, i;
    for( i = 1; i < koren; i++) {
        if(num % i == 0) brd += 2;
    }
    if(i * i == num) brd++;
    return brd;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long nmk;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> nc[i];
    if(n % 2 != 0) {
        dwc.push_back({nc[n / 2], nc[n / 2]});
        for(int i = 0; i < n / 2; i++) dwc.push_back({nc[n / 2 - i], nc[n / 2 + i]});
    } else {
        dwc.push_back({nc[n / 2 - 1], nc[n / 2]});
        for(int i = 0; i < n / 2; i++) dwc.push_back({nc[n / 2 - 1 - i], nc[n / 2 + i]});
    }
    nmk = max(nc[0], nc[n - 1]);
    if(!equal_ost(2)) {
        if(nmk % 2 == 0) nmk--;
    } else {
        if(nmk % 2 != 0) nmk--;
    }
    while(!equal_ost(nmk)) nmk -= 2;
    cout << br_del(nmk);

    return 0;
}
