#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, q, num, nomz;
    cin >> n >> q;
    vector <int> nc;
    for(int i = 0; i < n; i++) {
        cin >> num;
        nc.push_back(num);
    }
    for(int i = 0; i < q; i++) {
        cin >> nomz;
        if(nomz == 1) {
            nc.pop_back();
        }
        if(nomz == 2) {
            cin >> num;
            nc.push_back(num);
        }
        if(nomz == 3) {
            cin >> num;
            cout << nc[num - 1] << "\n";
        }
    }

    return 0;
}
