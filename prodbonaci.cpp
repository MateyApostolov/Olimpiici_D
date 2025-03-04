#include <bits/stdc++.h>
using namespace std;

int newz (int num) {
    int newn = 0, hi = 0, c;
    if(num == 0) return 9;
    while(num > 0) {
        c = num % 10;
        if(c == 0) c = 9;
        else c--;
        newn = pow(10, hi) * c + newn;
        num /= 10;
        hi++;
    }
    return newn;
}

int main () {
    int n, a, b;
    cin >> n >> a >> b;
    vector <int> pfib;
    pfib.push_back(newz(a));
    pfib.push_back(newz(b));
    for(int i = 2; i < n; i++) {
        int help = pfib[pfib.size() - 1] * pfib[pfib.size() - 2];
        help = newz(help);
        pfib.push_back(help % 1000);
        if(pfib[pfib.size() - 1] == b && pfib[pfib.size() - 2] == a) {
            pfib.pop_back();
            pfib.pop_back();
            if(n % pfib.size() == 0) {
                cout << pfib[pfib.size() - 1];
            } else {
                cout << pfib[(n % pfib.size()) - 1];
            }
            return 0;
        }
    }
    cout << pfib[n - 1];
    return 0;
}
