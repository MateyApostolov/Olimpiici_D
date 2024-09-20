#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);
    int n, q, num, nomz, h = 0;
    cin >> n >> q;
    vector <int> nc;
    for(int i = 0; i < n; i++) {
        cin >> num;
        nc.push_back(num);
    }
    for(int i = 0; i < q; i++) {
        cin >> nomz;
        if(nomz == 1) {
            h++;
        }
        if(nomz == 2) {
            cin >> num;
            nc.push_back(num);
        }
        if(nomz == 3) {
            cin >> num;
            cout << nc[num - 1 + h] << "\n";
        }
    }

    return 0;
}
