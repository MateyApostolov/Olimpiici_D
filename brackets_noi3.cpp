#include <bits/stdc++.h>
using namespace std;

int main () {
    char s;
    stack <pair<char, int>> open;
    vector <pair<int, int>> pos;
    int brb = 0, i = 0;
    while(cin >> s) {
        i++;
        if(s == '(') {
            open.push({s, i});
        }
        if(s == ')') {
            if(!open.empty()) {
                pos.push_back({open.top().second, i});
                open.pop();
                brb++;
            }
        }
    }
    for(int i = 0; i < pos.size(); i++) {
        cout << pos[i].first << ' ' << pos[i].second << '\n';
    }
    return 0;
}
