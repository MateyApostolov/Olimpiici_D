#include <bits/stdc++.h>
using namespace std;

int main () {
    string s;
    cin >> s;
    int sum = 0;
    for(int i = 0; i < s.size(); i++) {
        if(isupper(s[i])) {
            sum += (s[i] - 'A' + 1) % 9;
            if((s[i] - 'A' + 1) % 9 == 0) sum += 9;
        } else {
            sum += (s[i] - 'a' + 1) % 9;
            if((s[i] - 'a' + 1) % 9 == 0) sum += 9;
        }
    }
    while(sum >= 10) {
        if(sum == 33) break;
        int h1 = sum, h2 = 0;
        while(h1 > 0) {
            h2 += h1 % 10;
            h1 /= 10;
        }
        sum = h2;
    }
    cout << sum;
    return 0;
}
