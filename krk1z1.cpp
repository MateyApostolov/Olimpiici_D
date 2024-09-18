#include <bits/stdc++.h>
using namespace std;

int brdel(int num) {
    int br = 0, i;
    for(i = 1; i * i < num; i++) {
        if(num % i == 0) {
            br += 2;
        }
    }
    if(i * i == num) {
        br++;
    }
    return br;
}

int main () {
    int n;
    cin >> n;
    cout << brdel(n);

    return 0;
}
