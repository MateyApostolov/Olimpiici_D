#include <bits/stdc++.h>
using namespace std;

void hanoi_towers(int n, char C, char H, char T) {
    if(n == 1) {
        cout << "Move disk #1 from " << C << " to " << T << '\n';
        return;
    }
    else {
        hanoi_towers(n - 1, C, T, H);
        cout << "Move disk #" << n << " from " << C << " to " << T << '\n';
        hanoi_towers(n - 1, H, C, T);
    }
}

int main () {
    int n;
    cin >> n;
    hanoi_towers(n, 'A', 'B', 'C');
    return 0;
}
