#include <bits/stdc++.h>
using namespace std;

int kantor (int n, int pr) {
    if(n == 1) {
        for(int i = 0; i <= pr; i++) {
            cout << '*';
        }
        cout << '\n';
        return 1;
    }
    int k = kantor(n - 1, pr + 1);
    for(int i = 0; i < k; i++) {
        for(int i = 0; i <= pr; i++) {
            cout << '*';
        }
        cout << '\n';
    }
    k = kantor(n - 1, pr + 1);
    k *= 3;
    return k;
}

int main () {
    int n;
    cin >> n;
    kantor(n, 0);
    return 0;
}
