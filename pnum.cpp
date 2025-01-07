#include <bits/stdc++.h>
using namespace std;

vector <int> bs_2 (int num) {
    vector <int> d2;
    while(num > 0) {
        d2.push_back(num % 2);
        num /= 2;
    }
    return d2;
}

long long bs_p (vector <int> num, int p) {
    long long nc = 0, st = 1;
    for(int i = 0; i < num.size(); i++) {
        nc += num[i] * st;
        st *= p;
    }
    return nc;
}

int main () {
    int n, p, i = 0;
    cin >> n >> p;
    while(true) {
        i++;
        vector <int> d2 = bs_2(i);
        long long num = bs_p(d2, p);
        if(num > n) break;
        cout << num << '\n';
    }
    return 0;
}
