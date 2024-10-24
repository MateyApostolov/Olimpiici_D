#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, d, br = 0;
    char c;
    cin >> n;
    vector <int> r, g, b;
    for(int i = 0; i < n; i++) {
        cin >> c >> d;
        if(c == 'r') r.push_back(d);
        if(c == 'g') g.push_back(d);
        if(c == 'b') b.push_back(d);
    }
    for(int i1 = 0; i1 < r.size(); i1++) {
        for(int i2 = 0; i2 < g.size(); i2++) {
            for(int i3 = 0; i3 < b.size(); i3++) {
                int A = r[i1], B = g[i2], C = b[i3];
                if(A + B > C && B + C > A && C + A > B) br++;
            }
        }
    }
    cout << br;
    return 0;
}
