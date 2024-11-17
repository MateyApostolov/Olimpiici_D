 #include <bits/stdc++.h>
using namespace std;

int main () {
    string s, minh;
    cin >> s;
    bool iso = false, t = true;
    if(s[0] == '-') iso = true;
    if(!isdigit(s[0])) s = s.substr(1, s.size() - 1);
    for(int i1 = 0; i1 < s.size() - 1; i1++) {
        for(int i2 = i1 + 1; i2 < s.size(); i2++) {
            for(char c1 = '0'; c1 <= '9'; c1++) {
                for(char c2 = '0'; c2 <= '9'; c2++) {
                    if(s[i1] == c1 || s[i2] == c2) continue;
                    string hs = s;
                    hs[i1] = c1;
                    hs[i2] = c2;
                    if(hs[0] == '0') continue;
                    if((hs[hs.size() - 1] - '0') % 2 != 0) continue;
                    int sum = 0;
                    for(int hi = 0; hi < hs.size(); hi++) {
                        sum += hs[hi] - '0';
                    }
                    if(sum % 3 != 0) continue;
                    if(t) {
                        minh = hs;
                        t = false;
                    }
                    if(!iso) {
                        minh = max(minh, hs);
                    } else {
                        minh = min(minh, hs);
                    }
                }
            }
        }
    }
    if(iso) cout << '-';
    cout << minh;
    return 0;
}
