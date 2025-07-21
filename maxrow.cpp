#include <bits/stdc++.h>
using namespace std;

string s;
vector <string> row;

void sp (int p) {
    int hi = p + 1;
    string prh = row[row.size() - 1], h = "";
    if(hi + 1 < s.size() && s[hi + 1] == '0') return;
    while(hi + 1 < s.size() && prh > h + s[hi + 1]) {
        hi++;
        h += s[hi + 1];
    }
    row.push_back(h);
    sp(hi);
}

int main () {
    cin >> s;
    if(s[0] == '0') {
        cout << -1;
        return 0;
    }
    for(int i = 0; i < s.size(); i++) {
        row.push_back(s.substr(0, i + 1));
        sp(i);
        if(!row.empty()) break;
        row.clear();
    }
    cout << row.size();
    for(int i = 0; i < row.size(); i++) {
        cout << row[i] << ' ';
    }

    return 0;
}
