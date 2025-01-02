#include <bits/stdc++.h>
using namespace std;

const int maxn = pow(10, 5);
long long n, nc[maxn];
vector <pair<long long, long long>> dwc;

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
    long long nmk, q, qc;
    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> nc[i];
    if(n % 2 != 0) {
        dwc.push_back({nc[n / 2], nc[n / 2]});
        for(int i = 0; i < n / 2; i++) dwc.push_back({nc[n / 2 - i], nc[n / 2 + i]});
    } else {
        dwc.push_back({nc[n / 2 - 1], nc[n / 2]});
        for(int i = 0; i < n / 2; i++) dwc.push_back({nc[n / 2 - 1 - i], nc[n / 2 + i]});
    }
    nmk = max(dwc.back().first, dwc.back().second);
    while(!equal_ost(nmk)) nmk--;
    int brdr = br_del(nmk);
    cout << brdr << '\n';
    stack <int> ans;
    ans.push(brdr);
    for(int i = 0; i < q; i++) {
        cin >> qc;
        if(qc == 1) {
            int l, r;
            cin >> l >> r;
            dwc.push_back({l, r});
            nmk = max(l, r);
            while(!equal_ost(nmk)) nmk--;
            brdr = br_del(nmk);
            ans.push(brdr);
            cout << brdr << '\n';
        }
        if(qc == 2) {
            dwc.pop_back();
            ans.pop();
            if(!ans.empty()) {
                cout << ans.top() << '\n';
            } else {
                nmk = max(dwc.back().first, dwc.back().second);
                while(!equal_ost(nmk)) nmk--;
                brdr = br_del(nmk);
                ans.push(brdr);
                cout << brdr << '\n';
            }
        }
    }

    return 0;
}

