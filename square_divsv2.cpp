#include <bits/stdc++.h>
using namespace std;

vector <int> del(int num) {
    vector <int> d;
    double koren = sqrt(num);
    int i;
    for(i = 1; i < koren; i++) {
        if(num % i == 0) {
            d.push_back(i);
            d.push_back(num / i);
        }
    }
    if(i * i == num) {
        d.push_back(i);
    }
    return d;
}

int br_del(int num) {
    double koren = sqrt(num);
    int i, br = 0;
    for(i = 1; i < koren; i++) {
        if(num % i == 0) {
            br += 2;
        }
    }
    if(i * i == num) {
        br++;
    }
    return br;
}

int main () {
    int n;
    cin >> n;
    vector <int> deln = del(n);
    unordered_map <long long, bool> razd;
    for(int i1 = 0; i1 < deln.size(); i1++) {
        for(int i2 = 0; i2 < deln.size(); i2++) {
            razd[(long long)deln[i1] * deln[i2]] = true;
        }
    }
    int brn = razd.size();
    cout << brn;
    return 0;
}
