#include <bits/stdc++.h>
using namespace std;

vector <char> novs (vector <char>& s) {
    vector <char> news;
    for(int i = 0; i < s.size(); i++) {
        if((i + 1) % 3 == 0) continue;
        news.push_back(s[i]);
    }
    reverse(news.begin(), news.end());
    return news;
}

int main () {
    char ns;
    vector <char> s;
    while(cin >> ns) {
        s.push_back(ns);
    }
    while(s.size() > 2) {
        s = novs(s);
    }
    sort(s.begin(), s.end());
    cout << s[0] << s[1];
    return 0;
}
