#include <bits/stdc++.h>
#define int long long

using namespace std;

int br[20]; /// br[i] колко цифри имам като долепя всички числа с <= i цифри
int mind[20];

int dgs(int n) {
    int br = 0;
    while (n != 0) {
        br++;
        n/=10;
    }
    return br;
}

int digits(int a) {
    for (int i = 1; i <= 17; i++) {
        if (br[i] >= a) return i;
    }
    return -1;
}

int calc(int a, int total) {
    if (a > total-1) {
        a -= total-1;

        int digitsa = digits(a);
        a -= br[digitsa-1];
        int x = mind[digitsa]+(a-1)/digitsa;
        int y = (a-1)%digitsa;
        return to_string(x)[y]-'0';
    } else {
        a = total-a+1;

        int digitsa = digits(a);

        a -= br[digitsa-1];
        int x = mind[digitsa]+(a-1)/digitsa;
        int y = (a-1)%digitsa;
        string s = to_string(x);
        reverse(s.begin(), s.end());
        return s[y]-'0';
    }
}

main() {
    int n; cin >> n;

    int numbers = 9;
    for (int i = 1; i <= 17; i++) {
        br[i] = br[i-1]+i*numbers;
        numbers *= 10;
    }
    mind[1] = 1;
    for (int i = 2; i <= 17; i++) mind[i]=10*mind[i-1];

    int digitsn = dgs(n);
    int total = br[digitsn-1]+(n-mind[digitsn]+1)*digitsn;

    int a, b; cin >> a >> b;

    cout << calc(a, total)-calc(b, total) << endl;

    return 0;
}
