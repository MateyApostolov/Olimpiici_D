#include <bits/stdc++.h>
using namespace std;

int main () {
    string s;
    cin >> s;
    for(int i = s.size() - 2; i >= 1; i--) {
        bool t = true;
        for(int x = 0; x <= i / 2; x++) {
            if(s[x] != s[i - x - 1])  {
                t = false;
                break;
            }
        }
        if(t) {
            cout << i + 2 * (s.size() - i);
            return 0;
        }
    }

    return 0;
}
