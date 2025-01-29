#include <bits/stdc++.h>
using namespace std;

int main () {
    char s;
    stack <char> open;
    while(cin >> s) {
        if(s == '(') {
            open.push(s);
        }
        if(s == ')') {
            if(open.empty()) {
                cout << "NO";
                return 0;
            }
            open.pop();
        }
    }
    cout << "YES";
    return 0;
}
