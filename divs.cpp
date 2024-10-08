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
    int a, b;
    cin >> a >> b;
    vector <int> dela = del(a), delb = del(b);
    unordered_map <long long, bool> razd;
    for(int i1 = 0; i1 < dela.size(); i1++) {
        for(int i2 = 0; i2 < delb.size(); i2++) {
            razd[(long long)dela[i1] * delb[i2]] = true;
        }
    }
    int brab = razd.size(), br = 0;

    for(int i1 = 0; i1 < dela.size(); i1++) {
        for(int i2 = 0; i2 < delb.size(); i2++) {
            int dx = br_del(dela[i1]), dy = br_del(delb[i2]);
            if(brab % (dx + dy) == 0) {
                br++;
            }
        }
    }
    cout << br;
    return 0;
}
