#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, q, dif = 0;
    cin >> n;
    pair <string, int> cit[n];
    vector <pair<string, int>> difc;
    for(int i = 0; i < n; i++) {
        cin >> cit[i].first >> cit[i].second;
    }
    sort(cit, cit + n);
    for(int i = 0; i < n; i++) {
        if(i + 1 < n && cit[i].first == cit[i + 1].first) {
            dif += cit[i + 1].second;
        }
        if(i + 1 < n && cit[i].first != cit[i + 1].first) {
            difc.push_back({cit[i].first, dif});
            dif = 0;
        }
    }
    difc.push_back({cit[n - 1].first, dif});
    for(int i = 0; i < difc.size(); i++) {
        cout << difc[i].first << ' ' << difc[i].second << '\n';
    }
    return 0;
}
