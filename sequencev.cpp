#include <bits/stdc++.h>
using namespace std;

vector <int> novc (vector <int>& c) {
    vector <int> chv;
    for(int i = 0; i < c.size(); i++) {
        if(c[i] % 2 == 0) {
            chv.push_back(c[i]);
        }
    }
    return chv;
}


int main () {
    int n, nc;
    cin >> n;
    vector <int> c;
    for(int i = 0; i < n; i++) {
        cin >> nc;
        c.push_back(nc);
    }
    c = novc(c);
    cout << c[(c.size() - 1) / 2];


    return 0;
}
