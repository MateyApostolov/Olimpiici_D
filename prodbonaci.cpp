#include <bits/stdc++.h>
using namespace std;

int newz (int num) {
    int newn = 0, hi = 1, c;
    if(num == 0) return 9;
    while(num > 1) {
        c = num % 10;
        if(c == 0) c = 9;
        else c--;
        newn = hi * c + newn;
        num /= 10;
        hi *= 10;
    }
    return newn;
}

int main () {
    int n, a, b;
    cin >> n >> a >> b;
    vector <int> pfib;
    pfib.push_back(a);
    pfib.push_back(b);
    for(int i = 2; i < n; i++) {
        int help = pfib[pfib.size() - 1] * pfib[pfib.size() - 2];
        help = newz(help);
        a = b;
        b = help % 1000;
        pfib.push_back(b);
        if(i < 100000) continue;
        for(int x = 0; x < n - 2; x++) {
            if(pfib[x] == a && pfib[x + 1] == b) {
                int cyc = pfib.size() - 2 - x;
                cout << pfib[(n - x) % cyc + x - 1];
                return 0;
            }
        }
    }
    cout << pfib[n - 1];
    return 0;
}
