#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, p;
    cin >> n >> p;
    vector <char> s;
    s.push_back('a');
    for(int i = 1; i < n; i++) {
        vector <char> ns;
        ns.push_back(i + 'a');
        for(int x = 0; x < s.size(); x++) {
            ns.push_back(s[x]);
            ns.push_back(i + 'a');
        }
        s = ns;
    }
    for(int i = 0; i < s.size(); i++) cout << s[i];
    cout << '\n';
    if(p > s.size()) cout << 0;
    else cout << s[p - 1];
    return 0;
}
