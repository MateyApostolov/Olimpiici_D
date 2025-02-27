#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, k, m, nc;
    cin >> n >> k >> m;
    vector <int> fib;
    for(int i = 0; i < n; i++) {
        cin >> nc;
        fib.push_back(nc % m);
    }
    for(int i = 0; i < n; i++) {
        cin >> nc;
        fib[i] = (fib[i] * nc) % m;
    }
    if(k <= n) {
        cout << fib[k - 1] % m;
        return 0;
    }
    for(int i = n; i < k; i++) {
        fib.push_back(0);
        bool t = true;
        for(int x = 1; x <= n; x++) {
            fib[fib.size() - 1] = (fib[fib.size() - 1] + fib[fib.size() - x - 1]) % m;
        }
        for(int x = 1; x <= n; x++) {
            if(fib[x] != fib[fib.size() - x - 1]) t = false;
        }
        if(t) {
            for(int i = 0; i < n; i++) fib.pop_back();
            if(k % fib.size() == 0) {
                cout << fib[fib.size() - 1];
            } else {
                cout << fib[(k % fib.size()) - 1];
            }
            return 0;

        }
    }
    cout << fib[fib.size() - 1];
    return 0;
}
