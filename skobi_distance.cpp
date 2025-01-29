#include <bits/stdc++.h>
using namespace std;

int main () {
    char s;
    stack <pair<char, int>> open;
    int h = 0, maxd = 0;
    while(cin >> s) {
        h++;
        if(s == '(') {
            open.push({s, h});
        }
        if(s == ')') {
            maxd = max(maxd, h - open.top().second);
            open.pop();
        }
    }
    cout << maxd;
    return 0;
}
