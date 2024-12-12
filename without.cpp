#include <bits/stdc++.h>
using namespace std;

int main () {
    unsigned long long p, n, c = 1, num = 0;
    cin >> p >> n;
    while(n >= pow(p, c - 1) * c * (p - 1)) {
        n -= pow(p, c - 1) * c * (p - 1);
        num += pow(p, c - 1) * (p - 1);
        ///cout << n << ' ' << c << ' ' << num << '\n';
        c++;
    }
    num += n / c;
    if(n % c == 0) {
        ///cout << num << ' ';
        vector <char> nump;
        while(num > 0) {
            if(num % p > 9) {
                nump.push_back(char(num % p + 'A' - 10));
            } else {
                nump.push_back(char(num % p + '0'));
            }
            num /= p;
        }
        cout << nump[0];
    } else {
        num++;
        ///cout << num << ' ';
        vector <char> nump;
        while(num > 0) {
            if(num % p > 9) {
                nump.push_back(char(num % p + 'A' - 10));
            } else {
                nump.push_back(char(num % p + '0'));
            }
            num /= p;
        }
        reverse(nump.begin(), nump.end());
        unsigned long long ost = n % c;
        cout << nump[ost - 1];
    }



    return 0;
}
