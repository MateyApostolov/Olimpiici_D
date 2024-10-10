#include <bits/stdc++.h>
using namespace std;

int main () {
    long long n, a, b, h = 0, ha, hb;
    cin >> n >> a >> b;
    vector <int> c;
    for(int i = 1;  i <= n; i++) {
        long long num = i;
        while(num > 0) {
            c.push_back(num % 10);
            num /= 10;
        }
    }
    for(int i = 0;  i < c.size(); i++) {
        cout << c[i] << ' ';
    }
    ha = c[c.size() - a];
    hb = c[b - c.size()];
    cout << ha - hb;
    return 0;
}

