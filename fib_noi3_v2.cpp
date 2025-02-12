#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, m;
    cin >> n >> m;
    if(n < 3) {
        cout << 1;
        return 0;
    }
    vector <int> fib;
    fib.push_back(1);
    fib.push_back(1);
    for(int i = 2; i < n; i++) {
        fib.push_back((fib[fib.size() - 1] + fib[fib.size() - 2]) % m);
        if(fib[fib.size() - 1] == 1 && fib[fib.size() - 2] == 1) {
            fib.pop_back();
            fib.pop_back();
            if(n % m == 0) {
                fib[fib.size() - 1];
            } else {
                cout << fib[(n % m) - 1];
            }
            return 0;
        }
    }

    cout << fib[fib.size() - 1];
    return 0;
}
