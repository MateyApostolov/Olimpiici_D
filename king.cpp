#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, nc, i1 = 0, i2 = 0, minr = 1000;
    cin >> n;
    vector <int> r1;
    string s;
    getline(cin, s);
    stringstream ss;
    ss << s;
    while(ss >> nc) {
        r1.push_back(nc);
    }
    int r2[n - r1.size()];
    for(int i = 0; i < n - r1.size(); i++) {
        cin >> r2[i];
    }
    while(true) {
        if(r1[i1] == r2[i2]) break;
        int h1 = i1, h2 = i2;
        while(h1 < r1.size() && r1[h1] != r2[i2]) {
            h1++;
        }
        while(h2 < n - r1.size() && r2[h2] != r1[i1]) {
            h2++;
        }
        if(r1[h1] == r2[i2]) minr = min(minr, h1 + i2);
        if(r1[i1] == r2[h2]) minr = min(minr, i1 + h2);
        i1++;
        i2++;
    }
    cout << minr;
    return 0;
}
