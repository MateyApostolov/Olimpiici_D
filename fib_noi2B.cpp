#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, pr1 = 1, pr2 = 1, nc;
    cin >> n;
    for(int i = 3; i <= n; i++) {
        nc = (pr1 + pr2) % 100;
        pr2 = pr1;
        pr1 = nc;
    }
    cout << pr1;
    return 0;
}

