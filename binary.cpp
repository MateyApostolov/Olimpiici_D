#include <bits/stdc++.h>
using namespace std;

int main () {
    long long n, c = 1, num = 0;
    cin >> n;
    while(n >= pow(2, c - 1) * c) {
        n -= pow(2, c - 1) * c;
        num += pow(2, c - 1);
        ///cout << n << ' ' << c << ' ' << num << '\n';
        c++;
    }
    num += n / c;
    if(n % c == 0) {
        cout << num << ' ';
        vector <int> num2;
        while(num > 0) {
            num2.push_back(num % 2);
            num /= 2;
        }
        cout << num2[0];
    } else {
        num++;
        cout << num << ' ';
        vector <int> num2;
        while(num > 0) {
            num2.push_back(num % 2);
            num /= 2;
        }
        reverse(num2.begin(), num2.end());
        int ost = n % c;
        cout << num2[ost - 1];
    }



    return 0;
}
