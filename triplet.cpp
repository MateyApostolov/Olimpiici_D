#include <bits/stdc++.h>
using namespace std;

const int maxn = pow(10, 6);
long long prefd[maxn], prefu[maxn], ans;

int main () {
    string s;
    cin >> s;
    long long r[26] = {}, l[26] = {};
    for(int i = 0; i < s.size(); i++) {
        l[s[i] - 'a']++;
        for(int x = 0; x < s[i] - 'a'; x++) prefd[i] += l[x];
    }
    for(int i = s.size() - 1; i >= 0; i--) {
        r[s[i] - 'a']++;
        for(int x = s[i] - 'a' + 1; x < 26; x++) prefu[i] += r[x];
    }
    for(int i = 0; i < s.size(); i++) {
        ans += prefd[i] * prefu[i];
    }
    cout << ans;
    return 0;
}
