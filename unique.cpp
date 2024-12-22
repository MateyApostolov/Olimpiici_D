#include <bits/stdc++.h>
using namespace std;

string a, b, s;
bool usedig[10];
int br;

bool big(const string& a, string& b) {
    if(a.size() > b.size()) return false;
    if(a.size() < b.size()) return true;
    if(a <= b) return true;
    return false;
}

void back_tracking () {
    if(big(a, s) && big(s, b)) br++;
    for(int i = (s.empty() ? 1 : 0); i < 10; i++) {
        if(usedig[i]) continue;
        s += char(i + '0');
        usedig[i] = true;
        back_tracking();
        s.pop_back();
        usedig[i] = false;
    }
}

int main () {
    cin >> a >> b;
    back_tracking();
    cout << br;

    return 0;
}



