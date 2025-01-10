#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, div = -1, sum = 100000;
    cin >> n;
    double koren = sqrt(n);
    for(int i = 2; i <= koren; i++) {
        if(n % i == 0) {
            if(sum > i + (n / i)) {
                div = i;
                sum = i + (n / i);
            }

        }
    }
    if(div == -1) {
        cout << "No";
        return 0;
    }
    for(int x = 0; x < n - div - (n / div); x++) {
        cout << 1 << ' ';
    }
    cout << div << ' ' << n / div;
    return 0;
}
