#include <bits/stdc++.h>
using namespace std;

int main () {
    string s;
    cin >> s;
    vector <pair<int, int>> sk;
    stack <int> lp;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') lp.push(i);
        if(s[i] == ')') {
            sk.push_back({lp.top(), i});
            lp.pop();
        }
    }
    int br = pow(2, sk.size()) - 1;
    string ans[br];
    for(int i = 1; i <= br; i++) {
        int h = i;
        bool mp[s.size()] = {};
        for(int x = 0; x < br; x++) {
            if(h % 2 != 0) {
                mp[sk[x].first] = true;
                mp[sk[x].second] = true;
            }
            h /= 2;
        }
        for(int x = 0; x < s.size(); x++) {
            if(!mp[x]) ans[i - 1].push_back(s[x]);
        }
    }
    sort(ans, ans + br);
    cout << ans[0] << '\n';
    for(int i = 1; i < br; i++) {
        if(ans[i] != ans[i - 1]) cout << ans[i] << '\n';
    }
    return 0;
}
