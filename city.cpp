#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, m, h, v, nod = 0, c, ni;
    cin >> n >> m >> h >> v;
    long long hc[h + 1], vc[v + 1];
    vector <long long> del;
    for(int i = 0; i < h; i++) {
        cin >> c;
        hc[i] = c - 1;
    }
    for(int i = 0; i < v; i++) {
        cin >> c;
        vc[i] = c - 1;
    }
    hc[h] = n;
    vc[v] = m;
    sort(hc, hc + h);
    sort(vc, vc + v);
    for(int i = 0; i < h + 1; i++) {
        nod = __gcd(nod, hc[i]);
    }
    for(int i = 0; i < v + 1; i++) {
        nod = __gcd(nod, vc[i]);
    }
    ///cout << nod << '\n';
    double koren = sqrt(nod);
    for(ni = 1; ni < koren; ni++) {
        if(nod % ni == 0) {
            del.push_back(ni);
            del.push_back(nod / ni);
        }
    }
    if(ni * ni == nod) {
        del.push_back(ni);
    }
    sort(del.begin(), del.end());
    cout << del.size() << '\n';
    for(int i = 0; i < del.size(); i++) {
        cout << del[i] << ' ';
    }
    return 0;
}
