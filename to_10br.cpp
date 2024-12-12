#include <bits/stdc++.h>
using namespace std;

long long sb (string s, long long os) {
    long long sum = 0;
    for(long long i = 0; i < s.size(); i++) {
        if(isdigit(s[i])) {
            sum += (s[i] - '0') * pow(os, i);
        } else {
            sum += (s[i] - 'A' + 10) * pow(os, i);
        }
        cout << sum << '\n';
    }
    return sum;
}

int main () {
    long long n, num;
    string s;
    cin >> n >> s;
    reverse(s.begin(), s.end());
    num = sb(s, n);
    cout << num;
    return 0;
}

