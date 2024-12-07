#include <bits/stdc++.h>
using namespace std;

vector <int> red;

void r (int s) {
    if(s < 0) return;
    if(s == 0) {
        for(int i = 0; i < red.size(); i++) {
            cout << red[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 0; i < brc; i++) {
        red.push_back(num[]);
        r(s - 1);
        red.pop_back();
    }
}

int main () {
    int n, brc;
    cin >> n >> brc;
    int num[brc];
    for(int i = 0; i < brc; i++) {
        cin >> num[i];
    }
    r(n);
    return 0;
}
