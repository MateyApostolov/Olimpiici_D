#include <bits/stdc++.h>
using namespace std;

int n, br;

void gen (string s, int op, int cl) {
    if(op + cl == 2 * n) {
        br++;
        cout << s << '\n';
        return;
    }
    if(op < n) gen(s + '(', op + 1, cl);
    if(op > cl) gen(s + ')', op, cl + 1);
}

int main () {
    cin >> n;
    gen("", 0, 0);
    cout << br;
    return 0;
}
