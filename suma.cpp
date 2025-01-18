#include <bits/stdc++.h>
using namespace std;

unsigned long long sc (unsigned long long num) {
    while(num > 9) {
       unsigned long long h = num;
        num = 0;
        while(h > 0) {
            num += h % 10;
            h /= 10;
        }
    }
    return num;
}

int main () {
    unsigned long long q, s, f;
    cin >> q;
    for(int i = 1; i <= q; i++) {
        cin >> s >> f;
        unsigned long long sub = f - s + 1, c1 = sc(s), c2 = sc(f), sum = 0;
        if(sub < 10 && c1 <= c2) {
            while(c1 <= c2) {
                sum += c1;
                c1++;
            }
            cout << sum << '\n';
            continue;
        }
        if(sub <= 18) sum += (sub / 9 - 1) * 45;
        else sum += (sub / 9) * 45;
        while(c1 <= 9) {
            sum += c1;
            c1++;
        }
        while(c2 >= 1) {
            sum += c2;
            c2--;
        }
        cout << sum << '\n';
    }

    return 0;
}
