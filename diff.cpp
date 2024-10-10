#include <bits/stdc++.h>
using namespace std;

int main () {
    long long n, a, b, h = 0, ha, hb;
    cin >> n >> a >> b;
    for(int i = n; i > 0; i--) {
        long long num = i;
        while(num > 0) {
            h++;
            if(h == a) {
                ha = num % 10;
            }
            if(h == b) {
                hb = num % 10;
            }
            num /= 10;
        }
    }
    for(int i = 2;  i <= n; i++) {
        long long num = i;
        while(num > 0) {
            h++;
            if(h == a) {
                ha = num % 10;
            }
            if(h == b) {
                hb = num % 10;
            }
            num /= 10;
        }
    }
    cout << ha - hb;
    return 0;
}
