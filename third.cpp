#include <bits/stdc++.h>
using namespace std;

string novs (string s) {
    string news = s;
    int h = 0;
    for(int i = 0; i < s.size(); i++) {
        if((i + 1) % 3 == 0) continue;
            news[h] = s[i];
            h++;
    }
    return news;
}

int main () {
    string s;
    cin >> s;
    while(s.size() > 2) {
        s = novs(s);
    }
    cout << s;
    return 0;
}
