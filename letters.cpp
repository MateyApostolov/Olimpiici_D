#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, br1 = 0, br2 = 0, br3 = 0, br4 = 0;
    char a;
    cin >> n >> a;
    string s1, s2, s3, s4;
    for(int i = 0; i < n; i++) {
        int h = 0;
        cin >> s1 >> s2 >> s3 >> s4;
        if(s1[0] == a || s1[0] == a - ('a' - 'A')) br1++;
        if(s4[s4.size() - 1] == a || s4[s4.size() - 1] == a - ('a' - 'A')) br4++;
        for(int x = 0; x < s2.size(); x++) {
            if(s2[x] == a || s2[x] == a - ('a' - 'A')) {
                br2++;
                break;
            }
        }
        for(int x = 0; x < s3.size(); x++) {
            if(s3[x] == a || s3[x] == a - ('a' - 'A')) h++;
        }
        if(h >= 2) br3++;
    }
    cout << br1 << ' ' << br2 << ' ' << br3 << ' ' << br4;

    return 0;
}
