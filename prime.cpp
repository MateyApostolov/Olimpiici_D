#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000000000;
bool er[maxn];
vector <int> prd;
vector <int> del;

void eratosten () {
    for(int d = 2; d < maxn; d++) {
        if(!er[d]) {
            for(int h = d * d; h < maxn; h++) {
                er[h] = true;
            }
        }
    }
    return;
}

void find_del (int num) {
    int i;
    for(i = 0; i * i < num; i++) {
        if(num % i == 0) {
            del.push_back(i);
            del.push_back(num / i);
        }
    }
    if(i * i == num) {
        del.push_back(i);
    }
    return;
}

void set_pdel (int num) {
    for(int i = 2; i < maxn; i++) {
        if(!er[i]) {
            prd.push_back(i);
        }
    }

}

vector <int> kan_razlagane (int num) {
    int h = 0;
    vector <int> kand;
    while(num > 1) {
        if(num % prd[h] == 0) {
            kand.push_back(prd[h]);
            num /= prd[h];
        }
        h++;
    }
    return kand;
}

int main () {
    int n;
    cin >> n;
    find_del(n);
    eratosten ();


    return 0;
}
