#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    char s;
    stack <char> red;
    int brm = 0;
    while(cin >> s) {
        if(s == 'T') {
            while(!red.empty() && red.top() == 'O') {
                red.pop();
                brm--;
            }
            red.push(s);
        } else if(s == 'O') {
            if(!red.empty() && red.top() != 'L') {
                red.push(s);
                brm++;
            }
            if(red.empty()) {
                red.push(s);
                brm++;
            }
        } else if(s == 'L'){
            red.push(s);
        }
    }
    cout << red.size() << ' ' << brm;
    return 0;
}
