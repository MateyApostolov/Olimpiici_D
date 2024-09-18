#include <bits/stdc++.h>
using namespace std;

long long sum (long long n) {
    long long s = 1, i;
    double koren = sqrt(n);
    for(long long i = 2; i <= koren; i++) {
        if(n % i == 0) {
            s += i;
            if(i != n / i) s += n / i;
        }
    }
    return s;
}

int main () {
    long long num;
    cin >> num;
    cout << sum(num) << "\n";
    if(num < sum(num)) {
      cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
