#include <bits/stdc++.h>
using namespace std;

long long nc, nmsum = 10000000000;
vector <int> del;

long long nod(long long a, long long b) {
    if(a < b) {
        swap(a, b);
    }
    if(b == 0) {
        return a;
    }
    long long host;
    while(a % b != 0) {
        host = a % b;
        a = b;
        b = host;
    }
    return b;
}

void find_del(int num) {
    int i;
    for(i = 1; i * i < num; i++) {
        if(num % i == 0) {
            del.push_back(num / i);
            del.push_back(i);
        }
    }
    if(i * i == num) {
        del.push_back(i);
    }
}

int main () {
    cin >> nc;
    find_del(nc);
    for(int i = 0; i < del.size(); i++) {
        if(nod(del[i],  nc / del[i]) == 1) {
            nmsum = min(nmsum, del[i] + nc / del[i]);

        }
    }
    cout << nmsum;
    return 0;
}


