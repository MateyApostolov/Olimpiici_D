#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, s1 = 0, s2 = 0, h = 0;
    cin >> n >> m;
    int c1[n], c2[n];
    for(int i = 0; i < n; i++) {
        cin >> c1[i] >> c2[i];
        s1 += c1[i];
        s2 += c2[i];
    }
    for(int i = 0; i < m; i++) {
        s1 = s1 - c1[i] + c2[i];
        s2 = s2 - c2[i] + c1[i];
    }
    ///cout << '\n';
    while(h + m < n && s1 != s2) {
        ///cout << s1 << ' ' << s2 << '\n';
        s1 = s1 - c2[h] + c1[h];
        s1 = s1 - c1[m + h] + c2[m + h];
        s2 = s2 - c1[h] + c2[h];
        s2 = s2 - c2[m + h] + c1[m + h];
        h++;
    }
    if(s1 != s2) {
        cout << "N/A";
    } else {
        cout << h + 1;
    }

    return 0;
}
