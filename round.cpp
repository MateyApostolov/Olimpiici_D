#include <bits/stdc++.h>
using namespace std;

int main () {
    int num;
    cin >> num;
    vector <int> nc;
    num--;
    if(num == 0) {
        cout << 0;
        return 0;
    }
    while(num > 0) {
        nc.push_back(num % 2);
        num /= 2;
    }
    for(int i = nc.size() - 1; i >= 0; i--) {
        if(nc[i] == 1) {
            cout << 6;
        } else {
            cout << 0;
        }
    }
    return 0;
}
