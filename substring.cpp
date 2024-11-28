#include <bits/stdc++.h>
using namespace std;

int s1[26], s2[26];

int main () {
    string st1, st2;
    cin >> st1 >> st2;
    for(int i = 0; i < st1.size(); i++) {
        s1[st1[i] - 'a']++;
    }
    for(int i = 0; i < st2.size(); i++) {
        s2[st2[i] - 'a']++;
    }
    for(int i1 = 0; i1 < 26; i1++) {
        for(int i2 = 0; i2 < min(s1[i1], s2[i1]); i2++) {
            cout << char(i1 + 'a');
        }
    }
    return 0;
}
